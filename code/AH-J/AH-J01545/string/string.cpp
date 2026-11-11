#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;
string s[200005],S;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>s[i];
		for(int j=1;j<=a[i]/3;j++){
			S+=s[i];
			S+=s[i];
			S+=s[i];
		}
		int k=a[i]%3;
		for(int j=1;j<=k;j++)S+=s[i];
	}
	long long m=S.size();
	S=" "+S;
	for(int i=1;i<=m/2;i++){
		long long t=m-i+1;
		if(S[i]!=S[t])cnt++;
	}
	cout<<cnt;
    return 0;
}
