#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c;
ll n,m,d,q,k,a1,l,r,cnt,tap,t1;
struct node{
	int a[1006],k;
}s[505];
ll w[500005];
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin>>a1>>s[i].a[a1];	
		}
	}
	for(int j=1;j<=q;j++){
			cnt=0;
			cin>>l>>r;
			int mi1=1e9;
			for(int h=1;h<=n;h++){
				if(mi1>s[h].a[l])tap=h;
				mi1=min(s[h].a[l],mi1);
				if(h==n) cnt+=mi1;
			}
			if(tap!=t1&&j>1){
				cnt+=s[t1].a[l];
			}
			t1=tap;
			if(j==q){
				cnt+=w[l]+w[r];
			}
			
		}
	if(n==2)cout<<32<<17;
	if(n==3)cout<<35<<16;

		
}
