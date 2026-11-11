#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
struct Node{
	int a;
	char c;
}q[200010];
int la[200010];
char lc[200010];
signed main()
{
	freopen("string.in","r",stdin);//24474,479681762610,24104423
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin>>n;
	int x,le=0,op=0;
	char y;
	bool k=0;
	for(int i=1;i<=n;i++) {cin>>la[i]>>lc[i];le+=la[i];}
	
	x=la[1];y=lc[1];
	for(int i=2;i<=n;i++)
	{
		if(y==lc[i]) k=1,x+=la[i];
		else {
			q[++op]={x,y};
			x=la[i],y=lc[i];
			k=0;
		}
	}
		if(k) q[++op]={x,y};	
	
	
	/*/insite Vite 4
	string s;
	for(int i=1;i<=op;i++) {
		cout<<q[i].a<<' '<<q[i].c<<'\n';
		for(int j=1;j<=q[i].a;j++) s+=q[i].c;
	}
	//enddd Vutale 4*/
	
	int l=1,r=op,ans=0;
	while(l<=r)
	{
		if(q[l].c==q[r].c) {
			if(q[l].a>q[r].a) r--;
			else if(q[l].a<q[r].a) l++;
			else l++,r--;
		}else {
			if(q[l].a>q[r].a) ans+=q[r].a,r--;
			else if(q[l].a<q[r].a) ans+=q[l].a,l++;
			else ans+=q[l].a,l++,r--;
		}
	}
	cout<<ans;
	//cout<<s<<'\n'<<ans;
	return 0;
}
