#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500002];
int ans[300002];
struct q{
	bool b;
	int l;
}p[500002];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) p[j].b=0,p[j].l=0;
		for (int j=i;j<=n;j++){
			if(p[a[j]].b==0){
				p[a[j]].b=1;
				p[a[j]].l=j;
			}
			else{
				
				for(int k=p[a[j]].l;k<j;k++){
					p[a[k]].b=0;
					p[a[k]].l=0;
				}
				p[a[j]].b=1;
				p[a[j]].l=j;
			}
		}
		for (int j=1;j<=m;j++){
			ans[j]+=p[j].b;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
