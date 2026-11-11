#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int c[500005];
int dis[500005]; 
bool flag=true;
map<int,int> h;
int main(){
	freopen("card.in",r,stdin);
	freopen("card.out",w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=n-i+1;
		int k=1;
		int g;
		while(j--){
			for(int l=1;l<i;l++){
				if(c[l]==a[n-j+1]){
					flag=false;
					g=i;
				}
			}
			if(flag){
				c[k]=a[n-j+1];
				k++;
			}
			else{
				for(int i=g;i<=n;i++){
					c[i]=0;
				}
			}
		}
		for(int j=1;j<k;j++){
			h[k]+1;
		}
		memset(c,0,sizeof(c));
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<h[a[i]]<<" ";
	}
	return 0;
}
