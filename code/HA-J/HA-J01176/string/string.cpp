#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long k;
	cin>>k;
	int t=1;
	for(long long i=0;i<k;i++){
		bool w=0;
		long long m;
		char n;
		cin>>m>>n;
		if(m>=1000000000){
			t=100;
			w=1;
			
		}
		if(w==1){
			m/=100;
		}
		for(long long j=0;j<m;j++){
			s+=n;
		}
		
	}
	long long sum=0;
	long long c=s.size();
	for(long long i=0,j=c-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			sum+=t;
		}
	}
	cout<<sum;
	return 0;
}
