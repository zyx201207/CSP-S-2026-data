#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,sum=0;
	cin>>n;
	string s="";
	long long jia=0;
	char ad;
	for(int i=1;i<=n;i++){
		cin>>jia>>ad;
		for(long long j=1;j<=jia;j++){
			s+=ad;
		}
	}
	long long c=s.size();
	for(long long i=0;i<(c/2);i++){
		if(s[i]!=s[c-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

	
