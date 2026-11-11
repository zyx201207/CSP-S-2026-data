#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+6;
ll w[N];
int sum=0;
int m=0,n=0;
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	int c=0,d=0,q=0;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int sta=0;
		scanf("%d",&sta);
		for(int j=1;j<=sta;j++){
			int k=0,t=0; 
			scanf("%d %d",&k,&t);
		}
	}
	while(q--){
		int x=0,y=0;
		scanf("%d %d",&x,&y);
		sum=w[x]+w[y];
		cout<<sum<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
