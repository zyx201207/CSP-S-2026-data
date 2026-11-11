#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-1e9;
bool fa,fb,fc;
void dfs(int w,int pos){
	if (pos==n){
		maxx=max(maxx,w);
		return;
	}
	dfs(w&a[pos+1],pos+1);
	dfs(w,pos+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	if (a[i]>4) fc=1;
    	if (int(pow(2,log(a[i]+1)))!=a[i]+1) fa=1;
    	if (a[i]!=i-1) fb=1;
	}
    if (m==1){
    	int maxn=-1;
    	for (int i=1;i<=n;i++) maxn=max(maxn,a[i]);
	}
	if (m==2){
		int maxn=-1;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
	}
	if (m==n){
		int maxn=a[1];
		for (int i=2;i<=n;i++) maxn&=a[i];
	}
	if (fa==0){
		int minn=1e9;
		for (int i=1;i<=n;i++){
			minn=min(minn,a[i]);
		}
		cout<<minn;
	}
	if (fb==0){
		cout<<0;
	}
	if (fc==0){
		dfs(a[1],1);
		cout<<maxx;
	}
	return 0;
}
