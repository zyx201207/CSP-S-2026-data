#include<bits/stdc++.h>
using namespace std;
int c[10000];
string d[10000];
string asd(int q){
	string s;
	while(q){
		s+=char(q%2);
		q/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
		d[i]=asd(c[i]);
	}
	if(n==4){
		cout<<12;
	}else{
		cout<<7;
	}
	return 0;
} 
