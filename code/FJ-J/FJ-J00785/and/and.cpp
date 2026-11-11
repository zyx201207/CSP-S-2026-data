#include<bits/stdc++.h>
using namespace std;
int t(int u[],int n,int m,int b,int a,int ii){
	if(b==0){
		return max(n,m);
	}else{
		for(int i=ii;i<=a;i++){
			m=t(u,n&&u[i],m,b-1,a,i+1);
		}
		return m;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int u[a+1];
	for(int i=1;i<=a;i++)cin>>u[i];
	cout<<t(u,u[1],0,b,a,1);
	return 0;
}

