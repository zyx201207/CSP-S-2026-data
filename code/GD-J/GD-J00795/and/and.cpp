#include<bits/stdc++.h>
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+10;
void _freopen(){
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
int n,k;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
void solve2(){
	int ma=0;
	for(int i=1;i<=n;i++) ma=max(ma,a[i]);
	cout<<ma;
}
void solve3(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
void solve4(){
	int ans=a[1];
	for(int i=2;i<=n;i++) ans=ans&a[i];
	cout<<ans;
}
void solve5(){
	sort(a+1,a+1+n,cmp);
	cout<<a[k];
}
void solve6(){
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		int x=i,sum1=0;
		string st="";
		while(x>0){
			st=char(x%2+'0')+st;
			if(x%2==1) sum1++;
			x/=2;
		}
		while(st.size()<n){
			st="0"+st;
		} 
		if(sum1!=k) continue;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(st[j-1]!='1') continue;
			if(sum==0) sum=a[j];
			else sum=sum&a[j];
		}
		ans=max(ans,sum);
		//cout<<st<<" "<<sum<<endl;
	} 
	cout<<ans;
}
string c[N];
void solve7(){
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=k;i++){
		ans&=a[i];
	}
	cout<<ans;
}
struct A{
	int x;
	string st;
};
A d[N],dt[N],ss[N];
bool cmp2(A s,A t){
	if(s.st.size()!=t.st.size()) return s.st.size()>t.st.size();
	for(int i=1;i<=s.st.size();i++){
		if(s.st[i]!=t.st[i]) return s.st[i]>t.st[i];
	}
}
void solve8(){
	for(int i=1;i<=n;i++){
		int x=a[i];
		string s="";
		while(x>0){
			s=char(x%2+'0')+s;
			x/=2;
		}
		while(s.size()<30){
			s="0"+s;
		} 
		d[i].st=s;
		d[i].x=a[i];
	}
	sort(d+1,d+1+n,cmp2);
	int ans=d[1].x;
	for(int i=2;i<=k;i++){
		 ans&=d[i].x;
	}
	//cout<<ans;
	int ans2=0;
	for(int i=1;i<=n;i++){
		ss[i].x=d[i].x;
		ss[i].st=d[i].st;
	}
	int len=n;
	bool pp=0;
	for(int i=1;i<=30;i++){
		int sum=0,sum2=0;
		if(pp==0){
			for(int j=1;j<=n;j++){
				if(ss[j].st[i]=='1') sum++;
			}
			if(sum<8) continue;
			if(sum==8){
				for(int j=1;j<=len;j++){
					if(ss[j].st[i]!='1') continue;
					if(sum2==0)sum2=ss[j].x;
					else sum2&=ss[j].x;
				}
				cout<<sum2;
				return ;			
			}else{
				for(int j=1;j<=len;j++){
					if(ss[j].st[i]!='1') continue;
					dt[j].x=ss[j].x;
					dt[j].st=ss[j].st;
				
				}
			}
			pp=1;
		}else{
			for(int j=1;j<=n;j++){
				if(dt[j].st[i]=='1') sum++;
			}
			if(sum<8) continue;
			if(sum==8){
				for(int j=1;j<=len;j++){
					if(dt[j].st[i]!='1') continue;
					if(sum2==0)sum2=dt[j].x;
					else sum2&=dt[j].x;
				}
				cout<<sum2;
				return ;			
			}else{
				for(int j=1;j<=len;j++){
					if(dt[j].st[i]!='1') continue;
					ss[j].x=dt[j].x;
					ss[j].st=dt[j].st;
				}
			}
			pp=0;			
		}
	}
	cout<<ans;
}

int qp[N];
bool vis[1<<21];
void solve(){
	cin>>n>>k;
	bool p=0;
	qp[0]=1;
	vis[1]=1;
	for(int i=1;i<=20;i++) qp[i]=qp[i-1]*2,vis[qp[i]]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]+1]==0) p=1;
	}
	if(k==1) solve2();
	else if(k==2&&n<=2000) solve3();
	else if(k==n) solve4();
	else if(p==0) solve5();
	else if (n<=20) solve6();
	else solve8();
}
signed main(){
	No TLE
	_freopen();
	int T=1; 
	//cin>>T;
	while(T--){
		solve();
	}
}

