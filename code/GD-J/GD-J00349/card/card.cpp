#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int vi[5005];
int lan[5005];
int ls[5005];
int an[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vi,0,sizeof(vi));
		memset(lan,0,sizeof(lan));
		memset(ls,0,sizeof(ls));
		int cnt=1;
		for(int j=i;j<=n;j++){
			if(lan[a[j]]){
				cnt=ls[a[j]];
				for(int i=1;i<=m;i++){
					if(ls[i]>cnt){
						ls[i]=0;
						lan[i]=0;
					}
				}
			}else{
				vi[cnt]=a[j];
				lan[a[j]]++;
				cnt++;
				ls[a[j]]=cnt;
			}
		}
		for(int i=1;i<cnt;i++){
			an[vi[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<an[i]<<" ";
	}
	return 0;
}
