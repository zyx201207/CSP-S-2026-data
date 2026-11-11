#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n1,n2;
	string m1,m2;
	cin>>n1>>m1;
	cin>>n2>>m2;
	bool flag=0;
	if(n1==n2&&n1!=1&&n1!=16){
		cout<<1;
	}else{
		flag=1;
		cout<<0;
	}
	if(m1[0]==m2[0]&&m1[1]==m2[1]&&flag==0){
		cout<<1;
		if('A'<=m1[2]&&m1[2]<='C'&&'A'<=m2[2]&&m2[2]<='C'&&flag==0){
			cout<<1;
			if(abs(m1[2]-m2[2])==1&&flag==0){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}else{
			flag=1;
			cout<<0;
			cout<<0;
			return 0;
		}
		if('D'<=m1[2]&&m1[2]<='F'&&'D'<=m2[2]&&m2[2]<='F'&&flag==0){
			cout<<1;
			if(abs(m1[2]-m2[2])==1&&flag==0){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}else{
			flag=1;
			cout<<0;
			cout<<0;
			return 0;
		}
	}else{
		flag=1;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
