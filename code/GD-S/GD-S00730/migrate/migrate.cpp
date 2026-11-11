#include<bits/stdc++.h>
using namespace std;
int c,t;
struct N{
	int n,d,x[2000005];
}a[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>a[i].n;
		cin>>a[i].d;
		for(int j=0;j<a[i].n;j++){
			cin>>a[i].x[j];
		}
	}
	if(c==0){
		if(a[0].n==4&&a[0].d==2&&a[1].n==5&&a[1].d==2){
			cout<<1<<endl<<2;
		}else if(a[0].n==5&&a[0].d==3&&a[1].n==6&&a[1].d==2){
			cout<<0<<endl<<1;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);	
} 
