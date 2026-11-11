#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define int long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
const int mod=1;
template<typename T>inline void cmin(T&x,T y){x=(x<y?x:y);}
template<typename T>inline void cmax(T&x,T y){x=(x>y?x:y);}
template<typename T>inline int fplus(T x,T y){return x+y-(x+y>=mod?mod:0);}
template<typename T>inline void cplus(T&x,T y){x=fplus(x,y);}
template<typename T>inline int fminus(T x,T y){return x-y+(x-y<=0?mod:0);}
template<typename T>inline void cminus(T&x,T y){x=fminus(x,y);}
template<typename T>inline int qp(T x,T y){
	T ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ans;
}
inline void read(int&x){
	x=0;
	int p=1;
	char c=getchar();
	while(c<'0'||c>'9')p=(c=='-'?-1:p),c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=p; 
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+48);
}
bool be;
signed jmpl[2000005],jmpr[2000005];
signed cnt[2000005][4],mn[2000005][4],cmn[2000005][4],mn2[2000005][4],cmn2[2000005][4];
vector<pair<pii,int>>del[2000005];
inline void insert(int pos,int ty,int b,int c){
	if(!c)return;
	cnt[b][ty]+=c,del[pos].pb({{b,ty},c});
	if(ty==3)b=0;
	if(b>mn2[pos][ty])return;
//	cout<<"INS "<<pos<<' '<<b<<' '<<ty<<' '<<c<<' '<<cnt[6][2]<<'\n';
	if(b<mn[pos][ty])mn2[pos][ty]=mn[pos][ty],cmn2[pos][ty]=cmn[pos][ty],mn[pos][ty]=b,cmn[pos][ty]=c;
	else if(b==mn[pos][ty])cmn[pos][ty]+=c;
	else if(b<mn2[pos][ty])mn2[pos][ty]=b,cmn2[pos][ty]=c;
	else cmn2[pos][ty]+=c;
//	cout<<"INS "<<pos<<' '<<ty<<' '<<b<<' '<<c<<' '<<mn[pos][ty]<<'\n';
}
inline int calc(int n,int d,int*a){
	if(n==1)return 0;
//	cout<<d<<'\n';
	fo(i,2,n){
		jmpl[i]=max(jmpl[i-1],1);
		while(a[i]-a[jmpl[i]]>d)jmpl[i]++;
//		cout<<i<<' '<<jmpl[i]<<"  ";
	}
//	cout<<'\n';
	jmpr[n]=n+1;
	fd(i,n-1,1){
		jmpr[i]=min((int)jmpr[i+1],n);
		while(a[jmpr[i]]-a[i]>d)jmpr[i]--;
//		cout<<i<<' '<<jmpr[i]<<"  ";
	}
//	cout<<'\n';
	fo(i,1,n)mem(cnt[i],0),mem(mn[i],0x3f),mem(cmn[i],0),mem(mn2[i],0x3f),mem(cmn2[i],0),del[i].clear();
	insert(jmpr[1],3,1,1);
	int ret=0;
	fo(i,2,n){
		ret+=cnt[jmpl[i]][0]+cnt[jmpl[i]+1][2];
//		cout<<jmpl[i]<<' '<<cnt[jmpl[i]][0]<<" "<<cnt[jmpl[i]+1][2]<<'\n';
		if(i==n)break;
		for(auto j:del[i])cnt[j.fi.fi][j.fi.se]-=j.se;
//		cout<<"====== "<<i<<'\n';
//		fo(j,0,3)cout<<mn[i][j]<<" "<<cmn[i][j]<<"   "<<mn2[i][j]<<' '<<cmn2[i][j]<<'\n';
		if(mn[i][0]==jmpl[i])insert(jmpr[i],0,i,cmn[i][0]);
//		cout<<"!!!!!\n";
		if(jmpl[i]<i-1){
			if(mn[i][1]==jmpl[i]){
				if(jmpl[i-1]==jmpl[i])insert(jmpr[i],2,i,cmn[i][1]);
				else insert(jmpr[i],1,i,cmn[i][1]);
			}
			if(mn[i][2]==jmpl[i]){
				if(jmpl[i-1]==jmpl[i])insert(jmpr[i],2,i,cmn[i][2]);
				else insert(jmpr[i],1,i,cmn[i][2]);
				if(mn2[i][2]==jmpl[i]+1)insert(jmpr[i],0,i,cmn2[i][2]);
			}
			else if(mn[i][2]==jmpl[i]+1)insert(jmpr[i],0,i,cmn[i][2]);
			insert(jmpr[i],2,i,cmn[i][3]);
		}
		else{
			if(mn[i][1]==jmpl[i])insert(jmpr[i],3,i,cmn[i][1]);
			if(mn[i][2]==jmpl[i])insert(jmpr[i],3,i,cmn[i][2]);
			insert(jmpr[i],3,i,cmn[i][3]);
		}
		insert(jmpr[i],3,i,1);
//		cout<<i<<' '<<ret<<'\n';
//		cout<<cnt[6][2]<<' '<<cnt[4][2]<<'\n';

//		write(i),putchar(' '),write(ret),puts("");
//		if(i==3)cout<<cnt[3][3]<<'\n';
	}
	return ret;
}
int n,d,a[2000005],b[2000005];
void solve(){
	read(n),read(d);
	fo(i,1,n)read(a[i]);
	int cnt=0,ans=0;
	fo(i,1,n){
		b[++cnt]=a[i];
		if(i==n||a[i+1]-a[i]>d)ans+=calc(cnt,d,b),cnt=0;
	}
	write(ans),puts("");
}
bool bg;
signed main(){
//	#ifndef QWERTIM
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
//	#endif
//	freopen("migrate1.in","r",stdin);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T=1;
	read(c),read(T);
	while(T--)solve();
//	cerr<<'\n'<<abs((&be)-(&bg))/1048576.;
	return 0;
}
/*
0 1
7 2
0 2 4 5 6 7 9

6
0 0 0 0 0 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

6
*/
