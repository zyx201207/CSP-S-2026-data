#include<bits/stdc++.h>
using namespace std;
long long ans;

void dao(){
	long long n,d;
	cin>>n>>d;
	vector<long long>x(n+1);
	vector<long long>sa1;
	vector<long long>sa2;
	vector<long long>sa3;
	vector<long long>sa4;
	vector<long long>sa5;
	vector<long long>sa6;
	vector<long long>sa7;
	vector<long long>sa8;
	vector<long long>sa9;
	if(n<=9){
		for(int i=1;i<=n;++i){
		cin>>x[i];
	}
	for(long long i=1;i<=n;++i){
		for(long long j=1;j<=n;++j){
			if(i==j)continue;
			if(abs(x[i]-x[j])<=d&&i==1){
				sa1.push_back(j);
			}
			if(abs(x[i]-x[j])<=d&&i==2){
				sa2.push_back(j);
			}
			if(abs(x[i]-x[j])<=d&&i==3){
				sa3.push_back(j);
			}
			if(abs(x[i]-x[j])<=d&&i==4){
				sa4.push_back(j);
			}if(abs(x[i]-x[j])<=d&&i==5){
				sa5.push_back(j);
			}if(abs(x[i]-x[j])<=d&&i==6){
				sa6.push_back(j);
			}if(abs(x[i]-x[j])<=d&&i==7){
				sa7.push_back(j);
			}if(abs(x[i]-x[j])<=d&&i==8){
				sa8.push_back(j);
			}if(abs(x[i]-x[j])<=d&&i==9){
				sa9.push_back(j);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(i==1)continue;
	}
		
	}
	
	
}
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		dao();
	}
	cout<<ans;
	return 0;
}
