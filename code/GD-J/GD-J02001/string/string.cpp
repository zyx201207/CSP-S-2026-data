#include<bits/stdc++.h> 
using namespace std;
long long n,sum;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long m;
		char a;
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
		sum+=m;
	}
	long long cnt=0;
	for(long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

