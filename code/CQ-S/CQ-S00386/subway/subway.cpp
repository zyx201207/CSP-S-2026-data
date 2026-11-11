#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[10000];
struct node{
	long long a,t;
}a[10000][1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}for(int i=1,sl;i<=n;i++){
		cin>>sl;
		for(int j=1;j<=sl;j++){
			cin>>a[i][j].a>>a[i][j].t;
		}
	}
	return 0;
	
} 
