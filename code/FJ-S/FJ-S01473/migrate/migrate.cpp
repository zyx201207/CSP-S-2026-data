#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int a[2000005];
int w[2000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	if(11<=c&&12>=c){
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			if(d>=2*(a[1]-a[0])){
				cout<<(a[n-1]-a[0])/(a[1]-a[0])-1;
			}
			else{
				cout<<0;
			}
		}	
	}
	return 0;
}
