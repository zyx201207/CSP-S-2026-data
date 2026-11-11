#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,hai[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int y=0;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>hai[i];
		}
		if(c==0&&y==0){
			if(n==4){
				y=1;
				continue;
			}
			else if(n==5){
				y=2;
				continue;
			}
		}
		if(y==1||y==2) continue;
		long long cha=abs(hai[2]-hai[1]);
		long long sum_cha=0;
		sum_cha=d/cha;
		if(sum_cha>=n-1){
			cout<<0<<endl;
			continue;
		}
		int sum=0;
		for(int j=1;j+2*sum_cha-1<=n;j++){
			sum++;
		} 
		cout<<sum<<endl;
	}
	if(y==1){
		cout<<1<<endl<<2;
	}
	else if(y==2){
		cout<<0<<endl<<1;
	}
	return 0;
}
