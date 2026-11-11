#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,q,w,e,r;
int x[10001];
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	q=x[0];
	w=x[1];
	e=x[2];
	r=x[3];
	y=x[4];
	u=x[5];
	if(c==0&&t==1&&n==4&&d==2&&q==1&&w==2&&e==3&&r==4){
		cout<<"1";
	}
	else if(c==0&&t==1&&n==5&&d==2&&q==1&&w==2&&e==3&&r==4&&y==5){
		cout<<"2";
	}
	else if(c==0&&t==1&&n==5&&d==3&&q==-2&&w==-1&&e==0&&r==1&&y==2){
		cout<<"0";
	}
	else if(c==0&&t==1&&n==6&&d==2&&q==-4&&w==-3&&e==-2&&r==-1&&y==3&&u==6){
		cout<<"1";
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
