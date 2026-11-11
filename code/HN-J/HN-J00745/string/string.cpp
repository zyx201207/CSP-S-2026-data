#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	ll v;
	char c;
}a[N];
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].v>>a[i].c;
	
	int l=1,r=n;
	while(l<=r){
		node it1=a[l],it2=a[r];
		ll v1=it1.v,v2=it2.v;
		char c1=it1.c,c2=it2.c;
		if(c1==c2)
		{
			if(v1==v2) l++,r--;
			else if(v1>v2) r--, a[l]={v1-v2,c1};
			else l++,a[r]={v2-v1,c2};
			continue;
		}
		if(v1<v2)
		{
			l++;
			ans+=v1;
			a[r]={v2-v1,c2};
		}
		else if(v1>v2)
		{
			r--;
			ans+=v2;
			a[l]={v1-v2,c1};
		}
		else
		{
			l++;
			r--;
			ans+=v1;
		}
	}
	cout<<ans;
	return 0;
}
