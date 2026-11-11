//GZ-J00637,濮铭希,贵阳市第二十九中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],ans[M],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int y=0,flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=y;j++){
			if(a[i]==c[j]){
				break;
				flag=1;
			}	
		}
		if(flag==0){
			c[y+1]=a[i];
			y++;
		}
	}
	sort(c+1,c+1+y);
	for(int i=1;i<=n;i++){
		int b[N],x=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=x;k++){
				if(b[k]==a[j]){
					for(int v=k;v<j;v++){
						b[v]=0;
					}
				}
			}
			x++;
			b[x]=a[j];			
		}
		for(int j=1;j<=x;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[c[i]]<<' ';	
	}
	return 0;
}
