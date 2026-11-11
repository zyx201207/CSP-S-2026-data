#include<iostream>
using namespace std;
int    a	 [500005];
int lass 	 [500005];//最后一个a[i]的下标 
int lasw 	 [500005];//上一个和a[i]相同的数的下标 
int nexs 	 [500005];//最前一个a[i]的下标 
int nexw 	 [500005];//下一个和a[i]相同的数的下标 
int edge 	 [500005];
int in     	 [500005];
long long dp [500005];
long long ans[500005];
int q        [500005],head=1,tail=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lasw[i]=lass[a[i]];
		lass[a[i]]=i;
		nexs[a[i]]=500001;
	}for(int i=n;i>=1;i--){
		nexw[i]=nexs[a[i]];
		nexs[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(nexw[i]==500001){
			edge[i]=i+1;
			in[i+1]++;
		}else{
			edge[i]=lass[a[i]]+1;
			in[lass[a[i]]+1]++;
		}
	}for(int i=1;i<=n;i++){
		dp[i]=1;
		if(in[i]==0){
			q[++tail]=i;
		}
	}while(head!=tail+1){
		int f=q[head];
		head++;
		in[edge[f]]--;
		dp[edge[f]]+=dp[f];
		if(!in[edge[f]]){
			q[++tail]=edge[f];
		}
	}for(int i=1;i<=n;i++){
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)cout<<" ";
	}
	return 0;
}
