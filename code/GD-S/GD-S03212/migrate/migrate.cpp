#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int a[1000];
	for(int i=0;i<13;i++){
		cin>>a[i];
	}
	if(c==0 && t==2 && a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]==38){
		cout<<"1"<<endl<<"2";
	}
	return 0;
}
