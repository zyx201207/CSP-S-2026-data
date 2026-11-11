#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,t,n;
ll d,x[N],dp,minn=1e9,num,ans=0;
void f(int l,int r,int sum){
//	cout <<1<<endl;
	if(r==l){	
		if(sum<minn)minn=sum,num=0;
		else if(sum==minn)num++; 
	//	cout <<r<<" "<<sum<<" "<<minn<<" "<<num<<endl; 
		return ;
	}
	for(int i=l+1;i<=r;i++){
	//	cout <<i<<endl;
		if(x[i]-x[l]<=d)f(i,r,sum+1);
	}
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >>c>>t;
	while(t--){
		ll lx,l;
		cin >>n>>d>>lx;
		ans=0;
		for(int i=2;i<=n;i++){
			cin >>l;
			x[i]=l-lx+x[i-1];
			lx=l;
		}
		for(int k=1;k+3<=n;k++){
			for(int o=k+3;o<=n;o++){
				minn=1e9,num=0;
				//cout <<k<<"  "<<o<<endl;
				f(k,o,0);
				if(num==1)ans+=num;
			}	
		}
		cout <<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
