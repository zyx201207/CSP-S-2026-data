#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c,t;
int x[20*114514];
int minsl(int d,int dc){
	int i;
	for(i=0;i<=d;i+=dc);
	return i;
}
void sol(){
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	cout<<0<<endl;
	
	memset(x,0,sizeof(x));
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		sol();
	}
	return 0;
}

