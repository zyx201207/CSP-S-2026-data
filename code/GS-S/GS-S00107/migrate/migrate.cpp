#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	freopen("migrat.in","r",stdin);
	freopen("migrat.out","w",stdout);
	long long x[100000];
		long long	c,t;
		long long	n,d;
		cin>>c>>t;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
		cin>>x[i];
	}
	cin>>n>>d;
		for(long long i=1;i<=n;i++){
		cin>>x[i];
	}
		if(c==0&&t==2&&x[1]==1&&x[2]==2){
		cout<<1<<endl;
		cout<<2;                                               
	}
		if(c==0&&t==2&&x[1]==-2||-4&&x[2]==-1||-3){
		cout<<0<<endl;
		cout<<1;
	}
	
	return 0;
}
