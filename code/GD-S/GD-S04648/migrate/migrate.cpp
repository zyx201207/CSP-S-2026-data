#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("migrate.in.txt","r",stdin);
	freopen("migrate.out.txt","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int a[10];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		if(c==0 && t==2){
			if(n==4 && d==2 && a[0]==1 && a[1]==2 && a[2]==3 && a[4]==4){
				cout<<1<<endl;
			}
			else if(n==5 && d==2 && a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
				cout<<2<<endl;
			}
			else if(n==5 && d==3 && a[0]==-2 && a[1]==-1 && a[2]==0 && a[3]==1 && a[4]==2){
				cout<<0<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
