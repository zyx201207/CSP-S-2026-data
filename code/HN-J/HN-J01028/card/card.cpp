#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],mp[1000000],ans[1000000];
bool flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]){
			flag=0;
		}
		mp[a[i]]++;
	}
	if(flag){
		for(long long i=1;i<=n;i++){
			if(mp[a[i]]==1){
				mp[a[i]]=i;
			}
			else{
				mp[a[i]]--;
			}
		}
		for(long long i=1;i<=m;i++){
			cout<<mp[i];
			if(i!=m){
				cout<<' ';
			}
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			mp[j]=0;
		}
		for(long long j=i;j<=n;j++){
			if(mp[a[j]]){
				for(long long k=mp[a[j]];k<j;k++){
					mp[a[k]]=0;
				}
			}
			mp[a[j]]=j;
		}
		for(long long j=1;j<=m;j++){
			if(mp[j]){
				ans[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m){
			cout<<' ';
		}
	}
	return 0;
}

