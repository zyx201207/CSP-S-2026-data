#include<bits/stdc++.h>
using namespace std;
long long a,b,pa,pb,la,lb;
string A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>A>>b>>B;
	pa=(A[0]-'0')*10+A[1]-'0';
	pb=(B[0]-'0')*10+B[1]-'0';
	la=A[2];
	lb=B[2];
	if(a==b){
		if(pa==pb){
			if((A[2]<'D' && B[2]<'D' )||(A[2]>'C' && B[2]>'C')){
				if(la-lb<2 && la-lb>-2){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
