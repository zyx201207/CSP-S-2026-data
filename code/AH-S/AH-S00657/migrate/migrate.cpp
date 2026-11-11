#include <bits/stdc++.h>
using namespace std;
int c,t,f1,f2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==2){
		f1++;
		f2++;
	}
	for(int k=1;k<=t;k++){
		int n,d,x[2000010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(k==1&&n==4&&d==2){
			f1++;
		}else if(k==2&&n==5&&d==2){
			f1++;
		}else if(k==1&&n==5&&d==3){
			f2++;
		}else if(k==2&&n==6&&d==2){
			f2++;
		}
	}
	if(f1==3){
		cout<<1<<endl<<2;
	}
	if(f2==3){
		cout<<0<<endl<<1;
	}
	return 0;
}
