#include<bits/stdc++.h>
using namespace std;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,x;
	char y;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s+=y;
		}
	}
	long long l=0;
	long long ans=s.size();
	if(ans%2==0){
		while(l<=ans/2){
			long long r=ans-l;
			if(s[l]!=s[r]) cnt++;
			l++;
		}
	}
	else{
		while(l<=ans/2-1){
			long long r=ans-l-1;
			if(s[l]!=s[r]) cnt++;
			l++;
		}
	}
	cout<<cnt;

	return 0;
}
