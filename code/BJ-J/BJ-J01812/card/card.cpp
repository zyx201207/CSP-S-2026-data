#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
struct node{
	bool v;
	int c;
}b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]].v){
				for(int k=b[a[j]].c;k<j;k++){
					b[a[k]].v=0;
					b[a[k]].c=0;
				}
			}
			b[a[j]].v=1;
			b[a[j]].c=j;
		}
		for(int i=1;i<=m;i++){
			if(b[i].v)ans[i]++;
			b[i].v=0;
			b[i].c=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
