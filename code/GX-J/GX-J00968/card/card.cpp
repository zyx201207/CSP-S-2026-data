#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int a[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	srand(time(0));
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int j=1;j<=m;j++){
		int ans=abs(rand()%(n+1));
		while(ans==0)	ans=abs(rand()%(n+1));
		cout<<ans<<' ';
	}
	return 0;
}
