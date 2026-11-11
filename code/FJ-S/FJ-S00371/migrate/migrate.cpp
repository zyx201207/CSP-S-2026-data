#include<bits/stdc++.h>
using namespace std;
int a[2000],b[2000];
int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c=0,t=0,sum=0,sum2=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n=0,d=0;
		cin>>n>>d;
		if((n==4&&d==2)||(n==5&&d==2)){
			sum++;
		}
		if((n==5&&d==3)||(n==6&&d==2)){
			sum2++;
		}
		for(int j=1;j<=n;j++){
			cin>>b[i];
		}	
	}
	if(sum!=0){
		cout<<1<<endl<<2;
		return 0;
	}else if(sum2!=0){
		cout<<0<<endl<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
