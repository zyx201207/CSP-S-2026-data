#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a=0,b=0;
	string A,B;
	cin>>a>>A>>b>>B;
	
	int a_p=0;
	int b_p=0;
	a_p=(A[0]-'0')*10+A[1]-'0';
	b_p=(B[0]-'0')*10+B[1]-'0';
	bool ok3=(a==b);
	if(ok3){
		cout<<1; 
	}else{
		cout<<0;
	}
	bool ok2=(a_p==b_p);
	if(ok2&&ok3){
		cout<<1; 
	}else{
		cout<<0;
	}
//	for(int i='A';i!='G';i++){
//		cout<<i;
//	}
	bool ok=((A[2]>=65&&A[2]<=67)&&(B[2]>=65&&B[2]<=67))	||(	(A[2]>=68&&A[2]<=70)&&(B[2]>=68&&B[2]<=78));
	if(	ok&&ok3&&ok2){
		cout<<1; 
	}else{
		cout<<0;
	}
	if(ok&&ok2&&ok3&&(	abs(A[2]-B[2])<=1||	(	(A[2]>=68&&A[2]<=70)&&(B[2]>=68&&B[2]<=78)))	){
		cout<<1; 
	}else{
		cout<<0;
	} 
	return 0;
}

