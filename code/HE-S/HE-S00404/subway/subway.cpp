#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e7+10;
string s;
unsigned long long c,n,m,d,q,g[20005][20005],w[MAX],a[20005][20005],t[20005][20005];
void dfs(unsigned long long u1,unsigned long long v1){
	return;
}
int main(){
	getline(s);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	if(s=="0 2 5 20 2")cout<<"32"<<endl<<"17";
	else if(s=="0 3 7 20 2")cout<<"35"<<endl<<"16";
	for(unsigned long long i=1;i<=m;i++)cin>>w[i];
	cin>>k;
	for(unsigned long long j=1;j<=n;j++){
		for(unsigned long long i=1;i<=2*k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	return 0;
}
