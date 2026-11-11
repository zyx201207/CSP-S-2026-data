#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;

int n,a[N],cnt;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	for(int i=0;i<=s.size()/2;i++)if(s[i]!=s[s.size()-1-i])cnt++;
	cout<<cnt;
	
}

