#include<bits/stdc++.h>
using namespace std;
long long x,y;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>x>>y;long long a[x];
	vector<long long>v[x];
//	long long aa[x][x]={};
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	for(long long i=0;i<x-1;i++){
		for(long long j=i+1;j<x;j++){
			long long k=abs(a[i]-a[j]);
			v[i].push_back(k);
			v[j].push_back(k);
		}
	}
	long long f=0;
	for(int i=0;i<x;i++){
		sort(v[i].begin(),v[i].end());
		long long c=0,p=0;
		for(int j=0;j<v[i].size();j++){
			if(c+v[i][j]<=y){
				c+=v[i][j];
				p+=1;
			}else{
				break;
			}
		}
		f=max(f,p);
	}
	cout<<f+1;
}
