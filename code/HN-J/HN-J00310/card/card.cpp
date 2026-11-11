//我是秦始皇，我还没有死，这道题目给我AC，我封你做AC大将军 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int f[500001];
int l[500001];
struct Node{
	int l;int f;
}as[500001];
int dif[500002];
int ans[500001];
bool cmp(Node n1,Node n2){
	return n1.f<n2.f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(as[a[i]].f==0)
				as[a[i]].f=i;
		}
		for(int i=n;i>=k;i--){
			if(as[a[i]].l==0)
				as[a[i]].l=i;
		}
		int minn=INT_MAX;
		for(int i=1;i<=m;i++){
//			cout<<as[i].l<<" "<<as[i].f<<endl;
			minn=min(minn,as[i].l);
			if(as[i].l==minn){
				dif[as[i].f]--;
				dif[as[i].l]++;
			}
			
			as[i].f=0;
			as[i].l=0;
		}
		for(int i=k;i<=n;i++){
			dif[i]+=dif[i-1];
//			cout<<dif[i]<<" ";
		}
//		cout<<endl;
		for(int i=k;i<=n;i++){
			if(dif[i]>=0){
				ans[a[i]]++;
			}
			dif[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
