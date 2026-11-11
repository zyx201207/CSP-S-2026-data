#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,e=0,ans=0,a;
    char b;
    stack<char>c;
    string s="";
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
        e+=a;
        for(long long j=0;j<a;j++)s=s+b;
	}
	for(long long i=0;i<e/2;i++)c.push(s[i]);
	long long k;
	if(e%2==1)k=e/2+1;
	if(e%2==0)k=e/2;
	while(!c.empty()){
		if(c.top()!=s[k])ans++;
	    c.pop();
	    k++;
	}
	cout<<ans;
    return 0;
}
