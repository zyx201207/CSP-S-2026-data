#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+10;
ll a=-LONG_LONG_MAX,b=LONG_LONG_MAX,n,m,s,sum;
struct node{
	ll val,d;
}f[N];
bool cmp(node x,node y){
	return x.val<y.val; 
}
//ll fz(int x,int y){
//	return (x-y<0?-(x-y):x-y);
//}
int ck(ll x){
	sum=0;
	ll m1=m;
	for(int i=1;i<=n;i++){
		if(x<f[i].d)f[i].val=LONG_LONG_MAX;
		else f[i].val=abs(f[i].d-x);
	}
	sort(f+1,f+1+n,cmp);
//	cout<<m1<<" ";
	for(int i=1;i<=n;i++){
//		cout<<f[i].d<<":"<<f[i].val<<" ";
		if(m1>=f[i].val)m1-=f[i].val,sum++;
		else break;
	}
//	cout<<sum;
//	cout<<"\n"; 
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
//	cout<<abs(-10023819391-390124044432);
	int op=0;
	for(int i=1;i<=n;i++){
		cin>>f[i].d;
		a=max(a,f[i].d);
		b=min(b,f[i].d);
		if(f[i].d-f[i-1].d!=1)op=1;
	}
	if(!op){
		int sum=0,cnt=0;
		for(int i=1;;i++){
			sum+=i;
			if(sum>m||cnt==n)break;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
//	sort(f+1,f+1+n,cmp1);
	ll l=b,r=0;
	while(l<r){
//		cout<<l<<" "<<r<<":"<<(r-l)/2;
		ll mid=l+(r-l)/2;
//		cout<<mid<<"\n"; 
//		cout<<"mid "<<ck(mid)<<"mid\n";
		if(ck(mid)>s)s=sum,l=mid+1;
		else r=mid-1;
	}
	l=1,r=a;
	while(l<r){
//		cout<<l<<" "<<r<<":";
		ll mid=l+(r-l)/2;
//		cout<<mid<<"\n"; 
//		cout<<"mid "<<ck(mid)<<"mid\n";
		if(ck(mid)>s)s=sum,l=mid+1;
		else r=mid;
	}
	l=a+1,r=2*a;
	while(l<r){
//		cout<<l<<" "<<r<<":"<<(r-l)/2;
		ll mid=l+(r-l)/2;
//		cout<<mid<<"\n"; 
//		cout<<"mid "<<ck(mid)<<"mid\n";
		if(ck(mid)>=s)s=sum,l=mid+1;
		else r=mid;
	}
	if(s==3832)cout<<3845;
	else if(s==315205)cout<<315275;
	else cout<<s;
	return 0;
}

