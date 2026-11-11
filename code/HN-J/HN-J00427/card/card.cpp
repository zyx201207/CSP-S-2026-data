#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5E5+78;
const int MAX_M=3E5+78;
int n,m,pre[MAX_M],c[MAX_M],a[MAX_N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
//		int a;
		cin>>a[i];
		if(pre[a[i]]!=0){
			vector<int>ls;
			for(int j=pre[a[i]]+1;j<i;j++){
				ls.push_back(a[j]);
			}
			sort(ls.begin(),ls.end());
			ls.erase(unique(ls.begin(),ls.end()),ls.end());
			for(int k=0;k<ls.size();k++){
				c[ls[k]]--;
			}
		}
		pre[a[i]]=i;
//		for(int i=1;i<=m;i++){
//			cout<<pre[i]+c[i]<<' ';
//		}
//		cout<<'\n';
	}
//	for(int i=m;i>=1;i--){
//		int now=pre[i];
//		for(int j=now;j>=1;j--){
//			for(int)
//		}
//	}
	for(int i=1;i<=m;i++){
		cout<<pre[i]+c[i]<<' ';
	}
}
