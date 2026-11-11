#include<bits/stdc++.h>
using namespace std;

int n,m,A[200005],maxn=INT_MIN,sum,w[10];
bool vis[200005];
void DFS(int s,int a){
	if(s>m){
		if(a>maxn){
			maxn=a;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(a==-1){
				DFS(s+1,A[i]);
			}else{
				DFS(s+1,a&A[i]);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(A[i]>=4){
			sum=1;
		}else{
			w[A[i]]++;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,A[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int xx;
		xx=A[1];
		for(int i=2;i<=n;i++){
			xx=xx&A[i];
		}
		cout<<xx;
		return 0;
	} 
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int a,t;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				if(t==0){
					a=A[j];
					t=1;
				}else{
					a=a&A[i];
				}
			}
			maxn=max(maxn,a);
		}
		cout<<maxn;
		return 0;
	}
	if(sum==0){
		if(w[2]+w[3]>=m){
			cout<<2;
			return 0;
		}
		if(w[1]+w[3]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	DFS(1,-1);
	cout<<maxn;
}
