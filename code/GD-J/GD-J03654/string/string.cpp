#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct mstring{
	ll a;
	char c;
}ms[200005];
char c1[999999999999999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll n,ans;
	cin>>n;
	ll msize=0;
	for(int i=0;i<n;i++){
		cin>>ms[i].a>>ms[i].c;
		for(int j=msize;j<msize+ms[i].a;j++){
			c1[j]=ms[i].c;
		}
	}
	if(msize%2==0){
		ans=msize/2;
	}else ans=(msize+1)/2;
	for(int i=0;i<ans;i++){
		if(ms[i].c==ms[msize-i-1].c)ans--;
	}
	cout<<ans;
	return 0;
}
