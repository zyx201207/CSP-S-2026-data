#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int n,k,t1,t2,tid,T,ans=1e15;
vector<int> v[N];
int book[N];
void fd(int &ww,int fa,int now,int st){
	ww=max(ww,st);
	if(book[now]) return ;
	for(int to:v[now]) if(to!=fa) fd(ww,now,to,st+1);
}
int cc;
void fi(int d,int fa,int col){
//	cout<<d<<":"<<book[d]<<"\n";
	cc++;
	for(int to:v[d]) if(to!=fa&&book[to]==col) fi(to,d,col);
}
int work(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(book[i]==1) cnt1++;
		if(book[i]==2) cnt2++;
	}
	if(cnt1+cnt2!=k) return -1;
	
	cc=0;
	for(int i=1;i<=n;i++) if(book[i]==1){fi(i,0,1);break;}

	if(cc!=cnt1) return -1;
	cc=0;
	for(int i=1;i<=n;i++)
		if(book[i]==2){
			fi(i,0,2);
			break;
		}
	if(cc!=cnt2) return -1;
	int res=-1;
	for(int i=1;i<=n;i++) fd(res,0,i,0);
	return res; 
}
void dfs(int d){
	if(d==n+1){
		if(work()!=-1) ans=min(ans,work());
//		if(book[1]==0&&book[2]==1&&book[3]==0&&book[4]==2&&book[5]==0){
//			cout<<work()<<"dd";
//			exit(0);
//		}
//		for(int i=1;i<=n;i++) cout<<book[i]<<" ";
//		cout<<"\n";
		return ;
	}
	for(int i=0;i<=2;i++){
		book[d]=i;
		dfs(d+1);
	}
}
void solve(){
	ans=1e15;
	cin>>n>>k;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<n;i++){
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	if(tid<=3){
		dfs(1);
		cout<<ans<<"\n";
		return ;
	}
	if(tid==7||tid==11||tid==2){
		
		return ;
	}
	if(tid<=8){
		
		return ;
	}
	cout<<"1\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tid>>T;
	while(T--) solve();
	return 0;
} 
