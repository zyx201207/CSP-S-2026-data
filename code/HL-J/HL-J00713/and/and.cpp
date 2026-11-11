#include<bits/stdc++.h>
using namespace std;
long long m;
int a[10005]={};
string b[100005]={};
int turn(int x,int z){
	int n=x,y=0,j=0;
	while(1){
		cout<<endl<<n;
		b[z][j]=char(n%2);
		int n=n/2;
		j++;
		if(n==0){
			cout<<endl<<n;
			b[z][j]=char(n%2);
			cout<<"!!!!!!!!!!!!!!!!!";
			break;
		}
	}
	cout<<char(b[z][j]);
}

int main(){
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
		turn(a[i],i);
	}
}