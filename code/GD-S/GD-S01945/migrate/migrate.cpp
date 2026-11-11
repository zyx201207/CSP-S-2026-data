#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
int c,t;
int n,idx;
const int N=2e5+6;
int a[N];
bool check(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])return false;

	}
	idx=a[2]-a[1];	
    return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(check()){
			if(d>=2*idx&&d<3*idx){
				cout<<n-3<<'\n';
				cout<<n-3<<'\n';
			}
			else{
				cout<<"0"<<'\n';
				cout<<"0"<<'\n';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

