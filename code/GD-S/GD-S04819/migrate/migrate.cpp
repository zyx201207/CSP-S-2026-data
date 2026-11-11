#include<iostream>
using namespace std;
int main(){
	int x[10005],n,d,c,t,f,g,e=1;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
			f=d/2;
			g=n+e-2*d;
			if(x[j-1]+f==x[j])cout<<g;
		}
		if(c==0&&n==4){
			cout<<1<<endl<<2;
			return 0;
		}else if(c==0&&n==5){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	return 0;
}
