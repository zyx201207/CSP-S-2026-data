#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],t[500010],ans[500010],add=0;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(t,0,sizeof(t));
			int sum=0;
			for(int j=i-1;j<=n;j++){
				if(t[a[j]]>=1){
					int f=0;
					for(int k=1;k<=n;k++){
						if(b[k]==a[j]){
							f=k;
							break;
						}
					}
					for(int k=f;k<=n;k++) b[k]=0,sum--,t[a[k]]--;
					b[++sum]=a[j];
					t[a[j]]++;
				}
				else{
					b[++sum]=a[j];
					t[a[j]]++;
				}
			}
			for(int j=1;j<=sum;j++){
				ans[++add]=a[j];
			}
		}
		for(int i=1;i<=m;i++){
			int x=0;
			for(int j=1;j<=add;j++){
				if(a[j]==i) x++;
			}
			cout<<x<<" ";
		}
	}
	else{
		for(int i=1;i<=m;i++) cout<<1<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/


