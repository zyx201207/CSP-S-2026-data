#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	vector<long long> num(n);
	for(long long i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	vector<long long> cha(n,0);
	vector<long long> pre(n,0); //以当前i前全同代价 
	for(long long i=1;i<n;i++){
		cha[i]=num[i]-num[i-1];
		pre[i]=cha[i]*i+pre[i-1]; 
	}
	long long ip=upper_bound(pre.begin(),pre.end(),m)-pre.begin();
	cout<<ip;
	cout<<flush;
	return 0;
}
