#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x1[2000005];
bool b;
long long cnt=1,sum=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;		
		for(int j=1;j<=n;j++){
				cin>>x1[j];
		}
		for(int j=1;j<=n-2;j++){
			if(x1[j+1]-x1[j]!=x1[j+2]-x1[j+1]) b=1;
		}
		if(b==0){
			cout<<cnt<<endl;
			cnt++;
		}
		else{
			cout<<sum<<endl;
			sum++;
		}
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6


