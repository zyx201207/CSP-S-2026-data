#include<bits/stdc++.h>
using namespace std;
int a[200005];
int t[20000];
int main(){
	feropen("migrate.in","r",stdin);
	feropen("migrate.out","w",stdout);
    int c,t,n,d,x=0;
    cin>>c>>t;
    cin>>n>>d;
    while(t--){
	for(int i=0;i<n;i++){
    	cin>>a[i];
    }
	cout<<a[n-8]/2+a[n]<<a[n-56]/3<<0;
	cout<<endl;
	
    }
return 0;
}
