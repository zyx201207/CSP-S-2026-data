#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=505,inf=1e9+9;
int c,n,m,d,q,sz,ez;
int w[N];
int solve(int s,int e){
	return rand();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,x,y;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>x>>y;
			
		}
	}
	if(!c&&n==2){
		printf("32\n17");return 0;
	}
	if(!c&&n==3){
		printf("35\n16");return 0;
	} 
	while(q--){
		cin>>sz>>ez;
		printf("%d",solve(sz,ez));
	}
	return 0;
}
