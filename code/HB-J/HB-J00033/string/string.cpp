#include <bits/stdc++.h>
using namespace std;
long long n,c[200010],l,r,cl,cr,ans,la;
string s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i){cin>>c[i]>>s[i];}
	l=1,r=n;
	cl=c[l],cr=c[r];
	while(l<r){
		if(cl>cr){if(s[l]!=s[r]){if(cr-c[r]>=cl-c[l]){ans+=c[r];}else{ans+=cr-(cl-c[l]);}}cr+=c[--r],la=1;}
		else if(cl<cr){if(s[l]!=s[r]){if(cl-c[l]>=cr-c[r]){ans+=c[l];}else{ans+=cl-(cr-c[r]);}}cl+=c[++l],la=0;}
		else{
			if(s[l]!=s[r]){if(la){ans+=c[r];}else{ans+=c[l];}}
			if(l+1==r||l+2==r) break;
			cl+=c[++l],cr+=c[--r];
		}
	}
	cout<<ans;
	return 0;
}
