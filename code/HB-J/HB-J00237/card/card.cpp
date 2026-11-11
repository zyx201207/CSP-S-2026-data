#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long tap[500005],flag[500005];
map <long long,long long> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=1;i<=n;i++){
		memset(tap,0,sizeof(tap));
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(tap[a[j]]==0){
				tap[a[j]]++;
			}
			else{
				for(int k=flag[a[j]];k<j;k++){
					if(tap[a[k]])tap[a[k]]--;
				}
				tap[a[j]]++;
			}
			flag[a[j]]=j;
		}
		for(int j=1;j<=m;j++)mp[j]+=tap[j];
	}
	for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
	return 0;
}
