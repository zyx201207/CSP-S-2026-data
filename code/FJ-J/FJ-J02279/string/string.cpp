#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
long long cnt;
struct C{
	int a;
	char c;
}s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	r=n;
	while(l<r){
		if(s[l].c!=s[r].c) cnt+=min(s[l].a,s[r].a);
		if(s[l].a==s[r].a){
			l++;
			r--;
		}else if(s[l].a<s[r].a){
			l++;
			s[r].a-=s[l].a;
		}else{
			r--;
			s[l].a-=s[r].a;
		}
	}
	cout<<cnt;
	return 0;
}
