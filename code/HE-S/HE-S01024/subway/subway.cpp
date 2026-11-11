#include<bits/stdc++.h>
using namespace std;
int C,N,M,D,Q;
int a[600];
int d[2000000];
vector<int>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
 cin>>C>>N>>M>>D>>Q;
for(int i=1;i<=N;i++){
	cin>>a[i];
}
int x;
for(int i=1;i<=2*N+1;i++){
	cin>>d[i];
	if(i==3){
		x=d[i];
	}
}
for(int i=1;i<=Q;i++){
	int c,f;
	cin>>c>>f;
	cout<<abs(f-c)*x;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
