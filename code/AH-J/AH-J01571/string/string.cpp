#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n;
int a[N];
char b[N];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}

