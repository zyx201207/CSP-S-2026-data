#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,slen,mid,id;
struct node {
	int a;
	char c;
} s[MAXN],l,r;
int get(bool f) {
	int res=0;
	int now=0,j;
	for(register int i=1; i<=n; i++) {
		now+=s[i].a;
		if(now>=mid&&!f) {
			r.a=now-mid;
			r.c=s[i].c;
			l.a=s[i].a-r.a-1;
			l.c=s[i].c;
			//id=s[i].a-l.a;
			now=i;
			j=now;
			break;
		}else if(now>=mid&&f){
			r.a=now-mid-1;
			r.c=s[i].c;
			l.a=s[i].a-r.a-2;
			l.c=s[i].c;
			now=i;
			j=now;
			if(r.a<0){
				r.a=s[i+1].a-1;
				r.c=s[i+1].c;
				j=now+1;
				res++;
			}
			break;
		}
	}
	for(register int i=now;j<=n&&i>=1;) {
		if(l.c==r.c&&l.a!=0&&r.a!=0) {
			if(l.a>r.a) {
				l.a-=r.a;
				r.a=0;
			} else {
				r.a-=l.a;
				l.a=0;
			}
		} else if(r.a==0) {
			j++;
			r.c=s[j].c;
			r.a=s[j].a;
		} else if(l.a==0) {
			i--;
			l.c=s[i].c;
			l.a=s[i].a;
		} else if(l.c!=r.c) {
			if(l.a>r.a){
				res+=r.a;
				l.a-=r.a;
				r.a=0;
			}else{
				res+=l.a;
				r.a-=l.a;
				l.a=0;
			}
		}
	}
	return res;

}
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(register int i=1; i<=n; i++) {
		cin>>s[i].a>>s[i].c;
		slen+=s[i].a;
	}
	if(slen%2==0) {
		mid=slen/2;
		cout<<get(1);
	} else {
		mid=(slen+1)/2;
		cout<<get(0);
	}
	return 0;
}
