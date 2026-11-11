#include<bits/stdc++.h>
using namespace std;
const long long N=1e8+9,inf=1e8+9;
int x[N],s[N];
void solved(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=abs(x[i+1]-x[i]); 
	}
	int h=n-1;
	cout<<h/2<<endl;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int t; cin>>t; while(t--)
	solved();
	return 0;
}  
