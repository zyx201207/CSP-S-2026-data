#include <bits/stdc++.h>
using namespace std;

long long f(string s){
	long long len=s.size();
	long long c=(len-1)/2;
	long long cnt=0;
	for(long long i=0,j=len-1;i<=c,j>=c;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	return cnt;
} 
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	long long sum=0;
	string s;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		sum+=x;
		char op;
		cin>>op;
		for(long long j=1;j<=x;j++){
			s+=op;
		}
	}
	cout<<f(s)<<endl;
	return 0;
}
