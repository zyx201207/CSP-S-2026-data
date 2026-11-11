//#include <bits/stdc++.h>
//using namespace std;
//#define ull unsigned long long
//int n,m,maxn=0,maxd=0;
//pair<int,vector<int> > cnt[200005];
//ull a[200005];
//ull tmp;
//bool cmp(ull a,ull b){
//	return a>b;
//}
//bool e[200005][32];
//void wrt(ull x,int d,int o){
//	if(x==0) return;
//	e[o][d]=x%2;
//	cnt[d].first+=e[0][d];
//	cnt[d].second.push_back(o);
//	maxd=max(maxd,d);
//	wrt(x/2,d+1,o);
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
////	freopen("and.in","r",stdin);
////	freopen("and.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	tmp=a[1];
//	if(m==n){
//		for(int i=2;i<=n;i++){
//			tmp=tmp&a[i];
//		}
//		cout<<tmp;
//		return 0;
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		wrt(a[i],1,i);
//	}
//	for(int i=maxd;i>=1;i--){
//		if(cnt[i].first>=m){
//			maxd=m;
//		}
//	}
//	maxn=2<<maxd;
//	int mx=cnt[maxd].second.size();
//	for(int i=maxd-1;i>=1;i--){
//		for(int now=0;now<mx;now++){
//			if(e[cnt[maxd].second[now]][i]!=true){
//				cnt[maxd].second[now]=0;
//				for(int j=now+1;j<mx;j++){
//					cnt[maxd].second[j-1]=cnt[maxd].second[j];
//				}
//				mx--;
//			}
//		}
//		if(cnt[maxd].second.size()>=m){
//			maxn+=2<<i;
//		}
//	}
//	cout<<maxn<<endl;
//	return 0;
//} 
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,m,maxb=0;
ull maxn=0;
ull a[200005];
ull tmp;
bool vis[200005];
void dfs(int d,ull sum){
	if(d>m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(d==1) dfs(d+1,a[i]);
			else dfs(d+1,sum&a[i]);
			vis[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	tmp=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			tmp=tmp&a[i];
		}
		cout<<tmp;
		return 0;
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
} 
