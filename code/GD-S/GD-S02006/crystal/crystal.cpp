#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	int n,ans=1;
	long long m;
	cin>>n>>m;
	vector<long long>v;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;i++){
		v[i]=v[i+1]-v[i];
	}
	int p=0,q=0;
	long long z=0,zz=0;
	while(q<n-1){
		if(p>q){
			q++;
			z=v[q];
			zz=v[q];
			continue;
		}
		if(zz>m){
			zz-=z;
			z-=v[p];
			p++;
		}
		else{
			ans=max(ans,q-p+1);
			zz+=(q-p+1)*v[q];
			z+=v[q];
			q++;
		}
	}
	if(zz<=m)ans=max(ans,q-p+1);
	cout<<ans;
	return 0;
}
