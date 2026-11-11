#include<bits/stdc++.h>
using namespace std;
int c,t;

int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int x[100001];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(x[2]-x[1]==1){
            cout<<1<<endl;
        }else{
        cout<<0<<endl;}
    }

	return 0;
}
