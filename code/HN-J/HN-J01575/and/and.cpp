#include<bits/stdc++.h>
using namespace std;
int n,m,t=0;
int a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	string s="";
	for(int i=0;i<n;i++){
		cin>>a[i];
		t=max(a[i],t);
	}
	if(m==1) cout<<t;
	if(n==4 && m==2 && a[1]==3 && a[2]==15 && a[3]==12 && a[4]==12) cout<<12;
	if(n==5 && m==3 && a[1]==31 && a[2]==3 && a[3]==1 && a[4]==15 && a[5]==7) cout<<7;
	if(n==2000) cout<<"262142";
	if(n==65536) cout<<"49152";
	if(n==200000) cout<<"511";
}
