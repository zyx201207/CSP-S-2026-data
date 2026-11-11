#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
using namespace std;
struct node{
	ll cnt;
	char c;
}a[200005];
int n;
ll cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld %c",&a[i].cnt,&a[i].c);
		cnt+=a[i].cnt;
	}
	ll mid=cnt/2,now=0;
	int l=-1,r=-1;
	ll pos=-1;
	rep(i,1,n){
		if(now+a[i].cnt>=mid){
			if(now+a[i].cnt==mid){
				l=i;
			}else if(now+a[i].cnt>mid){
				r=i;
				if(now<mid){
					l=i;pos=now+a[i].cnt-mid;
				}
				break;
			}
		}
		now+=a[i].cnt;
	}
	if(r==-1)r=l+1;
	ll all=cnt;
	if(cnt&1){
		--all;
		--pos;
		if(l==r){
			--a[l].cnt;
		}
	}
	ll ans=0;
	now=0;
	while(now<all){
		if(l==r){
			if(a[l].cnt-pos<pos){
				a[r].cnt=pos-(a[l].cnt-pos);
				now+=(a[l].cnt-pos)*2ll;
				--l;
			}else{
				++r;
				a[l].cnt=a[l].cnt-pos-pos;
				now+=pos*2ll;
				if(!a[l].cnt)--l;
			}
		}else{
			if(a[l].cnt<a[r].cnt){
				a[r].cnt-=a[l].cnt;
				now+=a[l].cnt*2ll;
				ans+=a[l].cnt*(a[l].c!=a[r].c);
				--l;
			}else{
				a[l].cnt-=a[r].cnt;
				now+=a[r].cnt*2ll;
				ans+=a[r].cnt*(a[l].c!=a[r].c);
				++r;
				if(!a[l].cnt)--l;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

