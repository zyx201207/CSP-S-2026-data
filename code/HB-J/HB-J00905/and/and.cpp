#include<iostream>
using namespace std;
const int INF=2100000000;
int a[200005];
int b[200005];
int n,m;
int dp(int step,int left){
	int best=-INF;
	if(step==m){
		for(int i=left;i<n;i++){
			best=max(a[i],best);
		}
		return best;
	}
	for(int i=left;i<n;i++){
		if(b[i]==0){
			int now=max(a[i]&dp(step+1,i+1),best);
			best=max(best,now);
			b[i]=max(b[i],now);
		}
		else best=max(b[i],best);
	}
	return best;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dp(1,0);
	return 0;
}
