#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
long long n,d,sum;
int f(int x,int y){
	if(x==y) return ; 
	else{
		for(int i=x;i<=y;i++){
			
		}
	}
}
void slove(){	
	cin>>n>>d;
	int b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		 if(a[i]-a[i-1]>d){
		 	b=i;
		 }
	}
	int cnt=0;
	for(int i=1;i<b;i++){
		for(int j=i+3;j<=b;j++){
			f(i,j);
			if(sum==2)cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		slove();
	}
	return 0;
}
