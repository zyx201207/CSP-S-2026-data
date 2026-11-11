#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define x first
#define y second
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
typedef pair<int,char> pic;
vector<pic>s,t;
pic x;
signed main(){
	fre("string");
	int n;cin>>n;
	rep(i,1,n) cin>>x.x>>x.y,s.push_back(x);
	int ans=0;
	for(int i=0,j=n-1;i<=j;){
		if(s[i].x<s[j].x)
			ans+=(s[i].y==s[j].y?0:s[i].x),s[j].x-=s[i].x,i++;
		else if(s[i].x>s[j].x)
			ans+=(s[i].y==s[j].y?0:s[j].x),s[i].x-=s[j].x,j--;
		else ans+=(s[i].y==s[j].y?0:s[j].x),i++,j--;
	}
	cout<<ans;
}

