#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long b=0,d=1,e=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		if(c[i]==c[i-1])d++;
		if(i<=n/2&&c[i]==c[i-1]&&a[i]==a[i-1])e+=a[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	int l=s.size();
	if(d==n){
		cout<<0;
		return 0;
	}else if(d==n/2&&e==l/2){
		cout<<e;
		return 0;
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i]){
			s[l-i]=s[i];
			b++;
		}
	}
	cout<<b;
	return 0;
}
