#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	long long m=x[0]-'0',n=x[1]-'0';
	long long s=m*10+n;
	m=y[0]-'0',n=y[1]-'0';
	long long t=m*10+n;
	m=x[2]-'A'+1,n=y[2]-'A'+1;
	if(m==6) m--;
	if(n==6) n--;
	if(a!=b){
		cout<<"0000";
	}else{
		if(s!=t){
			cout<<"1000";
		}else{
			if(m<=3&&n>3){
				cout<<"1100";
			}else if(n<=3&&m>3){
				cout<<"1100";
			}else{
				if(m-n==1||n-m==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
