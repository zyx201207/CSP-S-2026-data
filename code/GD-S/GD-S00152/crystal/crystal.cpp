#include<bits/stdc++.h>
using namespace std;
long long n,m,maxs=1;
long long f(vector<long long> aa){
	sort(aa.begin(),aa.end());
	long long mcnt=0,mnum=aa[0],now=1;
	for(long long i=1;i<n;i++){
		if(aa[i]==mnum) now++;
		else{
			if(now>mcnt) mcnt=now;
			now=1;
			mnum=aa[i];
		}
	}
	return mcnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n);
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=1;i<n;i++){
		if(m-i>=0){
			m-=i;
			maxs++;
		}
		else break;
	}
	cout<<maxs;
	return 0;
}
