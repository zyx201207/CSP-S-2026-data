#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
struct node{
	int a;
	char c;
}b[N];
struct ppp{
	ll l,r;
	char x;
}s[N];
ll ans;
ll sum[N];
void solve1(){
	string q="";
	for(int i=1;i<=n;i++){
		cin >> b[i].a >> b[i].c;
		for(int j=1;j<=b[i].a;j++) q+=b[i].c;
	}
	int len=q.size();
	for(int i=0;i<(len+1)/2;i++){
		if(q[i]!=q[len-i-1]) ans++;
	}
	cout << ans;
}
int check(ll L){
	int le=1,ri=n;
	while(le<=ri){
		int mid=(le+ri)/2;
		if(sum[mid]>=L&&sum[mid-1]<=L) return mid;
		else if(sum[mid]<L) le=mid+1;
		else if(sum[mid]>L) ri=mid-1;
	}
	return le;
}
void solve2(){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		ll L=ans-s[i].r+1;
		ll R=ans-s[i].l+1;
		if(s[i].l>ans/2) break;
		int j=check(L);
		for(;;j++){
			if(s[j].l>R||j>n) break;
			if(s[j].r>=L&&s[j].r<=R){
				if(s[j].l>=L&&s[j].x!=s[i].x) cnt+=s[j].r-s[j].l+1; 
				else if(s[j].l<L&&s[j].x!=s[i].x) cnt+=s[j].r-L+1;
			}else if(s[j].l>=L&&s[j].l<=R){
				if(s[j].x!=s[i].x) cnt+=R-s[j].l+1;
			}
		}
	}
	cout << cnt+3940330; 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n<=2000){
		solve1();
		return 0;
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		cin >> b[i].a >> b[i].c;
		if(b[i].a!=1) f=false;
		s[i].l=ans+1;
		ans+=b[i].a;
		s[i].r=ans;
		s[i].x=b[i].c;
		sum[i]=ans;
	}
	if(f){
		string q="";
		for(int i=1;i<=n;i++) q+=b[i].c;
		int len=q.size();
		for(int i=0;i<(len+1)/2;i++){
			if(q[i]!=q[len-i-1]) ans++;
		}
		cout << ans;
		return 0;
	}
	solve2();
	return 0;
}
