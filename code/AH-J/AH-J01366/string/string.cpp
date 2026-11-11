#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
map<char,long long> mp1,mp2;
long long sum,ans;
struct node{
	int a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	}
	long long t=0;
	for(int i=1;t<sum/2;i++){
		mp1[s[i].c]+=s[i].a;
		t+=s[i].a;
	}
	for(int i=n/2+1+n%2;i<=n;i++){
		mp2[s[i].c]+=s[i].a;
	}
	if(n%2!=0&&s[n/2+1].a>1){
		mp1[s[n/2+1].c]+=s[n/2+1].a/2;
		mp2[s[n/2+1].c]+=(int)ceil(s[n/2+1].a*1.0/2)+sum%2;
	}
	for(char i='a';i<='z';i++){
		if(mp1[i]<mp2[i]) ans+=mp2[i]-mp1[i];
	}
	if(n%2==0&&sum%2!=0) ans-=1; 
	cout<<ans; 
	return 0;
}

