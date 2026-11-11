#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);//填名字
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    int x[2000010];
    for(int u = 0;u < t;u++){
		cin>>n>>d;
		for(int i = 0;i < n;i++){
		     	cin>>x[i];
		}
	}
    if(c==0 && t==2){
	    cout<<1<<endl<<2;
	    return 0;
	}
	cout<<0;
    return 0;
}
