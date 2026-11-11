#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,a[N],passed[N],res;
int valid[N][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int b=31;b>=0;b--)	valid[i][b]=(a[i]&(1<<b)); 
	}
	for(int b=31;b>=0;b--){
		int ans=0;
		for(int i=1;i<=n;i++)	ans+=(valid[i][b]&&(!passed[i]));
		if(ans<m)	continue;
		for(int i=1;i<=n;i++)
			if(!valid[i][b]||passed[i])	passed[i]=1;
		res|=(1<<b);
	} 
	cout<<res<<endl;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
