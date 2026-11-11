#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,sum=0;
	string s="";
	cin >> n;
	for(long long i=0;i<n;i++){
		long long a;
		cin >> a;
		sum+=a;
		string c;
		cin >> c;
		for(long long j=0;j<a;j++){
			s+=c;
		}
	}
	long long l=(sum+1)/2,r=(sum+1)/2;
	while(r<sum){
		if(s[l]!=s[r]){
			cnt++;
		}
		l--,r++;
	}
	cout << cnt;
} 
