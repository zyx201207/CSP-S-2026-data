#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
bool A=true;
int n,m;
int a[maxn];
int tmp[maxn];
int ans[maxn];
int last[maxn];
bool vis[maxn];
void dfs(){
	int cnt=1;
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=i;j<=n;j++){
			int lst=-1;
			for(int k=1;k<=cnt;k++){
				if(tmp[k]==a[j]){
					lst=k;
					break;
				}
			}
			if(lst==-1)tmp[cnt++]=a[j];
			else {
				cnt=lst+1;
			}
		}
		for(int j=1;j<cnt;j++){
//			cout<<tmp[j]<<' ';
			ans[tmp[j]]++;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return;
}
struct node{
	int x,id;
	node(){}
	node(int xx,int ii){
		x=xx,id=ii;
	}
	bool operator<(const node &r)const{
		if(x!=r.x)return x<r.x;
		return id<r.id;
	} 
}b[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=node(a[i],i);
		if(a[i]<a[i-1])A=false;
	}
	if(A){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	if(n<=200){
		dfs();
		return 0;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i].x==b[i-1].x)last[b[i].id]=b[i-1].id;
		else last[b[i].id]=0;
	}
	int lst=last[n];
	
	for(int i=n;i>=1;i--){
		if(i==n)ans[a[i]]=n;
		else{
			if(ans[a[i]]==0){
				memset(vis,0,sizeof(vis));
				int lst=0;
				int ii=i;
				while(ii){
					for(int j=n;j>ii;j--){
						vis[j]=1;
					}
					vis[a[ii]]=0;
					for(int j=ii-1;j>=1;j--){
						if(vis[j]){
							lst=j;
							break;
						}
					}
					ans[a[i]]+=ii-lst;
//					cout<<ii<<" "<<lst<<"\n";
					ii=last[ii];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
