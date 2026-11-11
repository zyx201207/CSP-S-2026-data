#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
string t,p;
char s[200005];
long long ans;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		cnt+=a[i];
	}
	long long d=0;
	if(cnt%2) d=cnt/2+1;
	else d=cnt/2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			t+=s[i];
		}
	}
	p=t;
	reverse(t.begin(),t.end());
	for(int i=0;i<d;i++){
		if(t[i]!=p[i]) ans++;
	}
	cout<<ans;
	return 0;
}
