#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
struct node{
	int ls,sum;
}num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) if(!num[a[i]].ls) num[a[i]].ls=i;
	//for(int i=1;i<=m;i++) cout<<num[i].ls<<" ";
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			l=num[a[l]].ls;
			num[a[l]].sum++;
			l++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",num[i].sum);
	return 0;
}
