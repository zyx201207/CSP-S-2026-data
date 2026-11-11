#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],B[300005],ans[300005],cnt;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(B,0,sizeof(B));
		cnt=0;
		for(int j=i;j<=n;j++){
			if(B[a[j]]!=0){
				for(int k=1;k<=m;k++){
					if(B[k]>B[a[j]]){
						B[k]=0;
					}
				}
			}
			B[a[j]]=++cnt;
		}
		for(int j=1;j<=m;j++){
			if(B[j]>0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
