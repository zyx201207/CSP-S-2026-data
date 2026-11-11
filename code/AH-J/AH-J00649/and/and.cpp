#include<bits/stdc++.h>
using namespace std;//OK 
long long a[200005];
vector<long long> vec,tmp;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	long long ans=0;
	for(int i=31;i>=0;i--){
		tmp.clear();
		long long l=(1LL<<i);
		int len=(int)vec.size();
		for(int j=0;j<len;j++){
			if((vec[j]&l)!=0)
				tmp.push_back(vec[j]);
		}
		if(tmp.size()>=m){
			vec.clear();
			int len1=(int)tmp.size();
			for(int j=0;j<len1;j++){
				vec.push_back(tmp[j]);
			}
			ans+=l;
		}
	}
	cout<<ans;
	return 0;
}
