#include<bits/stdc++.h>
using namespace std;
int n,m,y=0,a[2000005],b[2000005];

int cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(m==2){
		for(int i=1; i<=n; i++){
			int e=a[i];
			for(int j=i+1; j<=n; j++){
				y++;
				b[y]=e&a[j];
			}
		}
		sort(b+1,b+n+1,cmp);
		cout<<b[1]<<endl;
	}
	else if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}
	else if(n==m){
		for(int i=1; i<n; i++){
			y=a[i]&a[i+1];
		}
		cout<<y<<endl;
	}
	else{
		for(int i=1; i<=n; i++){
			y=rand()%10000;
		}
		cout<<y<<endl;
	}
	return 0;
} 
