#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int s,w;
	string a;
}a[200010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	a[0].w=1;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[i].s=a[i-1].s+a[i-1].w;
		a[i].w=x;
		cin>>a[i].a;
	}
	int len=a[n].s+a[n].w-1,now=0,ans=0;
	for(int i=1,j=n;now<len/2;i++){
		now+=a[i].w;
		while(a[i].w>0){
			a[i].w-=a[j].w;
			bool f=0;
			int t=a[j].w;
			a[j].w=0;
			if(a[i].w<0){
				a[j].w-=a[i].w;
				f=1;
				t-=a[j].w;
				a[i].w=0;
			}
			if(a[i].a!=a[j].a)ans+=t;
			if(f==0)j--;
		}
	}
	cout<<ans;
	return 0;
} 
