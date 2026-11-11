#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN=200005;
int n,c[MAXN],ans;
struct node{
	int a,c,l,r;
}a[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int cnt=1; 
	cin>>n;
	for(int i=1;i<=n;i++){
		char tmp;
		cin>>a[i].a>>tmp;
		a[i].c=tmp-'a';
	}
	for(int i=1;i<=n;i++){
		a[i].l=cnt;
		a[i].r=cnt+a[i].a-1;
		cnt+=a[i].a;
//		cout<<a[i].l<<' '<<a[i].r<<endl;
	}
	if(n>2000){
		for(int i=1;i<=n/2;i++){
			if(a[i].c!=a[n+1-i].c) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i].l>=cnt/2) break;
		int rr=cnt-a[i].l,rl=rr-a[i].r+a[i].l;
//		cout<<rl<<' '<<rr<<endl;
		for(int j=1;j<=n;j++){
			if(a[j].c!=a[i].c){
				if((a[j].l>=rl&&a[j].l<=rr)||(a[j].r>=rl&&a[j].r<=rr)){
					if((a[j].l>=rl&&a[j].l<=rr)&&(a[j].r>=rl&&a[j].r<=rr)) ans+=a[j].r-a[j].l+1;
					else if(a[j].l>=rl&&a[j].l<=rr) ans+=rr-a[j].l+1;
					else ans+=a[j].r-rl+1;
				}
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}
