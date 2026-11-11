#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l[114514*9/2],r[114514*9/2],L,lp,lpp,rpp,cnt=0;
unsigned long long rp=ULLONG_MAX;
char c[114514*9/2];

signed main(){
//	freopen("string.in","r",stdout);
//	freopen("string.out","w",stdin);
//	freopen("string.in","w",stdin);
//	freopen("string.out","r",stdout);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>c[i];
		l[i]=r[i-1]+1;
		r[i]=r[i-1]+x;
		L+=x;
	}
	if(L%2){
		lp=rp=(L+1)/2;
		for(int i=1;i<=n;i++) if(l[i]<=lp&&r[i]>=rp){
			lpp=rpp=i;
			break;
		}
	}else{
		lp=L/2,rp=L/2+1;
		for(int i=1;i<=n;i++) if(l[i]<=lp&&r[i]>=lp){
			lpp=i;
			break;
		}
		for(int i=1;i<=n;i++) if(l[i]<=rp&&r[i]>=rp){
			rpp=i;
			break;
		}
	}
//	cout<<L<<'\n'<<lp<<' '<<l[lpp]<<'\n'<<rp<<' '<<r[rpp]<<'\n';
	while(lp>=1&&lpp>=1&&rp<=L&&rpp<=n){
		int dis=min(lp-l[lpp],r[rpp]-(int)rp)+1;
		if(c[lpp]!=c[rpp]) cnt+=dis;
		int db;
		if(lp-l[lpp]<r[rpp]-(int)rp){
			rp+=dis;
			lp=r[--lpp];
			db=1;
		}else if(r[rpp]-(int)rp<lp-l[lpp]){
			lp-=dis;
			rp=l[++rpp];
			db=-1;
		}else{
			lp=r[--lpp];
			rp=l[++rpp];
			db=0;
		}
//		if(lp) cout<<lp<<' '<<rp<<' '<<dis<<' '<<db<<'\n';
	}
	cout<<cnt;
	return 0;
}
//调半天，原来是 19 行的 L 写成了 n，没绷住，饭堂了，time-=30min。 
