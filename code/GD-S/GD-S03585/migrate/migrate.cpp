#include<bits/stdc++.h>
using namespace std;
int c,t;long long cha,n,d,x[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		t--;n=0;d=0;cha=0;
		for(int i=0;i<2000010;i++){
			x[i]=0;
		}
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		cha=x[1]-x[0];
		if(d<cha*2||d>=cha*(n-1)){
			cout<<"0"<<endl;
			continue;
		}
		d=(d/cha)*cha;
		d=2*d-cha;
		if((n-1)*cha<d){
			cout<<"0"<<endl;
		}
		else{
			cout<<n-d/cha<<endl;
		}
	}
} 
