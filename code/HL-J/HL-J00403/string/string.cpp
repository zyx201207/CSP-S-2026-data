#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
char b[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long sum=0;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	for(int i=1;i*2<=cnt;i++){
		if(s[i]!=s[n-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
