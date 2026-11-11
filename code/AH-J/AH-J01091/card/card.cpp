#include<bits/stdc++.h>
using namespace std;
long f[100086];
long a[100086];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<long,long> mp;
	for(int i=n;i>=1;i--){
		if(mp[a[i]]!=0){
			for(int j=i+1;j<=mp[a[i]];j++){
				mp[a[j]]=0;
			}
			mp[a[i]]=i;
		}
		else{
			mp[a[i]]=i;
		}
		for(auto i=mp.begin();i!=mp.end();i++){
			if(i->second!=0){
				f[i->first]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
}
