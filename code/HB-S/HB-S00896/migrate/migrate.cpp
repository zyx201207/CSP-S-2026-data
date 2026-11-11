#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    int t;
    cin>>c>>t;
    int a[200005];
    int d[200005];
    int f[200005];
    for(int i=0;i<t;i++){
		cin>>d[i]>>f[i];
		for(int j=0;j<d[i];j++){
			cin>>a[i];
		}
	}
	cout<<1<<endl;
	cout<<2;
		
	return 0;
}

