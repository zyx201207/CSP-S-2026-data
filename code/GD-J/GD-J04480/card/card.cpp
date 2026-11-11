#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005];
int desktop[50005];
int tong[30005];
int sum[30005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		memset(desktop,0,sizeof(desktop));
		l=1;
		for(int j=i;j<=n;j++){
			bool flag=0;
			if(tong[a[j]]){
				for(int k=1;k<=l;k++){
					if(desktop[k]==a[j]){
						l=k;
						flag=1;
						break;
					}
				}
				if(flag){
					for(int x=l;x<=n;x++){
						tong[desktop[x]]--;
						desktop[x]=0;
					}
				}
			}
			desktop[l]=a[j];
			l++;
			tong[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(tong[j]>=1){
				sum[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	} 
	return 0;
}
