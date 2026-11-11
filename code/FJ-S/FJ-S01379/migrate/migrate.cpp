#include<bits/stdc++.h>
//#define int long long
#define LL long long
using namespace std;
inline LL read(){
	char c=getchar();
	LL ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
const int N=2e6+10;
int n,f[N],g[N],l[N],r[N];
int t[N*25],ls[N*25],rs[N*25],root[N],idx,cnt1[N],cnt2[N];
LL a[N],d;
#define lc ls[k]
#define rc rs[k]
void change(int &k,int l,int r,int x){
	if (!k) k=++idx;t[k]++;
//	cout <<k<<" "<<l<<" "<<r<<" "<<x<<endl;
	if (l==r) return ;
	int mid=l+r>>1;
	if (x<=mid) change(lc,l,mid,x);else change(rc,mid+1,r,x);
}
int ask(int k,int l,int r,int l1,int r1){
	if (!k||l1>r1) return 0;
	if (l1<=l&&r1>=r) return t[k];
	int mid=l+r>>1,ans=0;
	if (l1<=mid) ans+=ask(lc,l,mid,l1,r1);if (r1>mid) ans+=ask(rc,mid+1,r,l1,r1);
	return ans;
}
inline LL solve(int ll,int rr){
//	cout <<l<<" "<<r<<endl;
/*	LL ans=0;
	for (int i=ll;i<rr;i++){
		//i+1,i
		int cnt1=0,cnt2=0;
		for (int j=i+2;j<=r[i+1];j++) if (l[j]==i) cnt1++;
		if (l[r[i+1]]==i){
			int x=r[i+1];//,last=r[i+1];
			while(x<rr&&l[r[x]]==x){
				for (int j=x+1;j<=r[x];j++) if (l[j]==x) cnt1++;
			//	last=x;
				x=r[x];
			}
			for (int j=x+1;j<=r[x];j++) if (l[j]==x) cnt1++;
		}
//		cout <<r[1]<<endl;
		for (int j=l[i];j<i;j++) if (r[j]==i+1) cnt2++;
		if (r[l[i]]==i+1){
			int x=l[i];//last=l[i];
			while(x>ll&&r[l[x]]==x){
				for (int j=l[x];j<x;j++) if (r[j]==x) cnt2++;
			//	last=x;
				x=l[x];
			}
			for (int j=l[x];j<x;j++) if (r[j]==x) cnt2++;
		}
//		cout <<i<<" "<<cnt1<<" "<<cnt2<<endl;
		ans+=1ll*cnt1*cnt2;
	} */
	for (int i=1;i<=idx;i++) t[i]=ls[i]=rs[i]=0;idx=0;
	for (int i=ll;i<=rr;i++) root[i]=0;
	for (int i=ll;i<=rr;i++) change(root[l[i]],ll,rr,i);
	for (int i=rr-1;i>=ll;i--){
		cnt1[i]+=ask(root[i],ll,rr,i+2,r[i+1]);
//		for (int j=i+2;j<=r[i+1];j++) if (l[j]==i) cnt1[i]++;
		int x=r[i+1],tmp=0;
	//	for (int j=x+1;j<=r[x];j++) if (l[j]==x) tmp++;
		tmp=ask(root[x],ll,rr,x+1,r[x]);
		if (x<rr&&l[r[x]]==x) f[x]=f[r[x]]+tmp;else f[x]=tmp;
		if (l[r[i+1]]==i) cnt1[i]+=f[x];
	}
	for (int i=1;i<=idx;i++) t[i]=ls[i]=rs[i]=0;idx=0;
	for (int i=ll;i<=rr;i++) root[i]=0;
	for (int i=ll;i<=rr;i++) change(root[r[i]],ll,rr,i);
	for (int i=ll;i<rr;i++){
		cnt2[i]+=ask(root[i+1],ll,rr,l[i],i-1);
	//	for (int j=l[i];j<i;j++) if (r[j]==i+1) cnt2[i]++;
		int x=l[i],tmp=0;
	//	for (int j=l[x];j<x;j++) if (r[j]==x) tmp++;
		tmp=ask(root[x],ll,rr,l[x],x-1);
		if (x>ll&&r[l[x]]==x) g[x]=g[l[x]]+tmp;else g[x]=tmp;
		if (r[l[i]]==i+1) cnt2[i]+=g[x];
	}
	LL ans=0;
	for (int i=ll;i<rr;i++) ans+=1ll*cnt1[i]*cnt2[i];//,cout <<i<<" "<<cnt1[i]<<" "<<cnt2[i]<<endl;
	return ans;
} 
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
inline void solve(){
	n=read(),d=read();
	for (int i=1;i<=n;i++) a[i]=read(),cnt1[i]=cnt2[i]=f[i]=g[i]=0;
	int x=1;
	for (int i=1;i<=n;i++){
		while(x<=i&&a[x]<a[i]-d) x++;
		l[i]=x;
	}
	x=n;
	for (int i=n;i>0;i--){
		while(x>=i&&a[x]>a[i]+d) x--;
		r[i]=x;
	}
//	for (int i=1;i<=n;i++) cout <<l[i]<<" ";puts("");
//	for (int i=1;i<=n;i++) cout <<r[i]<<" ";puts("");
	int last=1;LL ans=0;
	for (int i=1;i<=n;i++) if (r[i]==i) ans+=solve(last,i),last=i+1;
	if (last<=n) ans+=solve(last,n);
	printf("%lld\n",ans);
//	cerr <<"dd\n";
}
main(){
//	system("fc migrate.out migrate3.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	change(root[2],1,3,1),change(root[1],1,3,3);cout <<ask(root[1],1,3,2,2)<<endl;return 0;
	read();int T=read();//T=1;
	while(T--) solve();
	cerr <<(double)clock()/CLOCKS_PER_SEC<<endl;
	return 0; 
}

