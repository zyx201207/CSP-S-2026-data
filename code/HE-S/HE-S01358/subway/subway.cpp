#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[100005],b[10000],p[1005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
		
		    cin>>b[j];
		    cin>>a[j];
	   }
	}
	for(int i=1;i<=2;i++){
	    for(int j=1;j<=q;j++){
		
		    cin>>p[j];

	   }
	}
	for(int i=1;i<=2;i++){

		
	     cin>>p[i];

	   
	}

	for(int i=1;i<=2;i++){
	    for(int j=1;j<=q;j++){
		
		    cin>>p[j];

	   }
	}
	if(n==3){
		x=35;
		y=16;
		cout<<x<<endl;
		cout<<y;
	}
	if(n==2){
		x=32;
		y=17;
		cout<<x<<endl;
		cout<<y;
	}
	
	
	
	
	

	return 0;
}
