#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int last=i;
		unordered_set<int> st;
		for(int j=i;j<=n;j++){
			if(st.count(a[j]))  last=j;
			else  st.insert(a[j]);
		}
		for(int j=last;j<=n;j++)  ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)  printf("%d ",ans[i]);
	return 0;
}
