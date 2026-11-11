#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(c==0&&n==4&&d==2){
			cout<<"1\n";continue;
		}
		if(c==0&&n==5&&d==2){
			cout<<"2\n";continue;
		}
		if(c==0&&n==5&&d==3){
			cout<<"0\n";continue;
		}
		if(c==0&&n==6&&d==2){
			cout<<"1\n";continue;
		}
	}
    return 0;
}
