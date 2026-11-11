#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;bool flg=0; 
	char c='?';
	while(c<'0'||c>'9'){
		c=getchar();
		if(c=='-')flg=1;
	}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	if(flg)x=-x;
	return;
}
int n,p,suf[2000005],pre[2000005];
long long d,a[2000005],ans;
int cnt[2000005],x[2000005],y[2000005];
long long sm[2000005],sm2[2000005];
int sizx,sizy,tmp[2000005],tmp2[2000005];
bool fl[2000005],Fl[2000005];
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;i++)read(a[i]),x[i]=y[i]=tmp[i]=tmp2[i]=0;
	p=1;
	for(int i=1;i<=n;i++){
		while((p<n)&&(a[p+1]-a[i]<=d))p++;
		suf[i]=p;
	}
	p=n;
	for(int i=n;i>=1;i--){
		while((p>1)&&(a[i]-a[p-1]<=d))p--;
		pre[i]=p;
	}
	for(int i=1;i<=n;i++)x[i]=y[i]=0;
	for(int i=1;i<=n;i++)
		if(i!=suf[i])x[suf[i]]++;
	for(int i=1;i<=n;i++)
		if(i!=pre[i])y[pre[i]]++;
	for(int i=1;i<=n;i++)fl[i]=((suf[i]!=i)&&(pre[suf[i]]==i)),Fl[i]=((pre[i]!=i)&&(suf[pre[i]]==i));
	for(int i=n;i>=1;i--)
		if(fl[i])tmp[i]=tmp[suf[i]]+y[suf[i]];
		else tmp[i]=0;
	for(int i=1;i<=n;i++)
		if(Fl[i])tmp2[i]=tmp2[pre[i]]+x[pre[i]];
		else tmp2[i]=0;
	ans=0;
	for(int i=1;i<n;i++){
		int A=i+1,B=i;
		if(pre[i+1]==i||suf[i]==i+1)continue;
		int sa=y[B],sb=x[A];
		if(pre[suf[i+1]]==i){
			A=suf[A],sa+=y[A];
			sa+=tmp[A];
//			int _=0;
//			while(fl[A])A=suf[A],sa+=y[A],_++;
		}
		if(suf[pre[i]]==i+1){
			B=pre[B],sb+=x[B];
			sb+=tmp2[B];
//			int _=0;
//			while(Fl[B])B=pre[B],sb+=x[B],_++;
		}
		ans=ans+1ll*sa*sb;
//		cout<<i+1<<" "<<i<<":"<<sa<<" "<<sb<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	read(c),read(T);
	while(T--)solve();
	return 0;
}
//x->y->z
//x->y+1->z
