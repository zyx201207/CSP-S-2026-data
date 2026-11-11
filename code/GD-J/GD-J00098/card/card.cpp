#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],ST[1000001],st[1000001],p[1000001];
stack<int> x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)st[j]=0,p[j]=0;
		for(int j=i;j<=n;j++){
			if(p[a[j]]==0&&st[a[j]]==0)ST[a[j]]++,p[a[j]]=1;
			if(st[a[j]]==0)x.push(a[j]),st[a[j]]=1;
			else{
				while(x.top()!=a[j]){
					st[x.top()]=0;
					x.pop();
				}
				st[x.top()]=0;
				x.pop();
				
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",ST[i]);
		printf(" ");
	}
	return 0;
}
