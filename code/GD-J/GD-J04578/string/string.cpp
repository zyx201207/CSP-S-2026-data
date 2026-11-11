#include<bits/stdc++.h>
using namespace std;
char c[200001];
string s;
long long n,b[200001];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		for(int j=1;j<=b[i];j++)s=s+c[i];
	}
	for(long long i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])sum++;
	cout<<sum;
	return 0;
}

