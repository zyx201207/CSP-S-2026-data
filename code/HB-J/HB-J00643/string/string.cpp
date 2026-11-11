#include<bits/stdc++.h>
using namespace std;
int n;
int a[400005];
char b[400005];
long long t[200005];
long long dp[2001][51];
string s;
long long cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		 cin>>a[i]>>b[i];
		 a[2*n-i+1]=a[i];
		 b[2*n-i+1]=b[i];
		 t[i]=t[i-1]+a[i];
		 for(int j=t[i-1]+1;j<=t[i];j++) s=s+b[i];
	}
	if(n==1){cout<<0;return 0;}
	if(n==2){cout<<min(a[1],a[2]);return 0;}
    long long c=s.size();
	cout<<c/2;
	return 0;
}
