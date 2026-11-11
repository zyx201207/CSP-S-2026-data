#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m,q,p;
	cin>>n>>m;
	int a,b,z=0;
	for(int c=1;c<=m;c++){
		cin>>a>>b;
	       for(int d=1;d<=a;d++){
		cin>>q>>p;
	z+=q;
		z+=p;
		z=z%(a+1);
			}
		if(z==0){
			cout<<1<<endl;
		}else{
			cout<<z<<endl;
		}
	}
	return 0;
}
