#include<bits/stdc++.h>
using namespace std;

int a[2000005];
int main(){
	freopen("migrate.cpp","r",stdin);
	freopen("migrate.cpp","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t,n,d,dd;
    cin>>c>>t;
    for(int i=0;i<t;++i){
		cin>>n>>d;
		for(int j=0;j<n;++j){
			cin>>a[j];
		}
		dd=a[2]-a[1];
		if(d>=dd*3) {cout<<1;}
		if(d<dd) {cout<<0;}
	}
    return 0;
}		
    
