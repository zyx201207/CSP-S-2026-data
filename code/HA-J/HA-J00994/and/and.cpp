#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxx,cnt,maxb;
long long _pow10[31];
struct eee{
	int a,xb;
	long long b,c;
}st[200005];
bool cmp(eee a,eee b){
	return a.b>b.b;
}
bool cmp1(eee a,eee b){
	return a.c>b.c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	_pow10[1]=1;
	for(int i=2;i<=11;i++){
		_pow10[i]=_pow10[i-1]*10;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st[i].a;
		st[i].xb=i;
	}
	for(int i=1;i<=n;i++){
		int h=st[i].a,cnt=0;
		while(h){
			cnt++;
			st[i].b+=(h%2)*_pow10[cnt];
			h/=2;
		}
		st[i].c=st[i].b;
	}
	sort(st+1,st+1+n,cmp);
	maxx=st[1].a;
	maxb=st[1].xb;
	for(int i=2;i<=n;i++){
		int x=st[1].b,y=st[i].b,cnt1=0;
		while(y){
			++cnt1;
			if(x%10==y%10&&x%10==0){
				st[i].c+=1*_pow10[cnt1];
			}
			y/=10;
			x/=10;
		}
	}
	sort(st+1,st+1+n,cmp1);
	for(int i=1;i<=m;i++){
		if(st[i].xb!=maxb){
			maxx&=st[i].a;
		}
	}
	cout<<maxx;
	return 0;
}
