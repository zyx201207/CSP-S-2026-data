#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
stack<long long>s;
map<long long,long long>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		long long cnt = i;
		for(int j = i;j<=n;j++){
			if(i!=j&&a[i]==a[j]){
				cnt = j;
			}
		}
		for(int j = cnt;j<=n;j++){
			mp[a[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}

