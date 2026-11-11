#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int m,n,maxx=-1;
void opp(int x,int a[],int y){
	if(x==m+1){
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		maxx=max(sum,maxx);
		return;
	}
	for(int i=y;i<=n;i++){
		a[x]=b[i];
		opp(x+1,a,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	opp(1,a,1);
	cout<<maxx;
	return 0;
}
