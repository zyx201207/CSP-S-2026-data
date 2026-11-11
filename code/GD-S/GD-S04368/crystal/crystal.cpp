#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m,maxx=0,x;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long sum=0;
	while(a.size()){
		long long sum=a[0];
		for(long long i=1;i<a.size();i++){
			if(sum+m>=i*a[i]){
				maxx=max(maxx,i);
			}
			sum+=a[i];
		}
		a.erase(a.begin()+0);
	}
	cout<<maxx+1;
	return 0;
}

