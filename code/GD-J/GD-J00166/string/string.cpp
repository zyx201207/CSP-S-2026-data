#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,le,ans,cnt;
struct str{
	ll l,r;
	char c; 
};
str a[N],b[N];

void get_ans(){
	ll x,y,px=1,py=le,s1=1,s2=cnt,sum1,sum2;
	while(s1<s2){
		x=a[s1].r,y=a[s2].l;
		sum1=x-px+1,sum2=py-y+1;
		if(a[s1].c!=a[s2].c){
			ans+=min(sum1,sum2);
		}
		if(le-y+1>x)
			s1++;
		else if(le-y+1<x)
			s2--;
		else
			s1++,s2--;
		px+=min(sum1,sum2);
		py-=min(sum1,sum2);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	ll ai,p=1;
	for(int i=1;i<=n;i++){
		cin>>ai>>b[i].c;
		le+=ai;
		b[i].l=p;
		b[i].r=p+ai-1;
		p+=ai;
	}
	for(int i=1;i<=n;i++){
		if(b[i].l<=(le+1)/2&&b[i].r>=(le+1)/2){
			ll z=le/2,y=z+1;
			if(le&1)
				y++;
			a[++cnt]={b[i].l,z,b[i].c};
			a[++cnt]={y,b[i].r,b[i].c};
		}
		else
			a[++cnt]=b[i];
	}
	get_ans();
	cout<<ans;
	return 0;
}
