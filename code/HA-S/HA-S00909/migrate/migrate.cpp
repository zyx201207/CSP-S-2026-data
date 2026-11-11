#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[9600000],num=0;
void op(int a,int b){
	if((b-a)%t==0){
		return ;
	}else if((b-a+1)/t==t||(b-a+1)/t==-t){
		num++;
		return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				op(j,k);
			}
		}
	    cout<<num<<endl;
		num=0;		
	}

	return 0;
}
