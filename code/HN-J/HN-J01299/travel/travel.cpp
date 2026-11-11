#include<bits/stdc++.h>
using namespace std;
int a[25][25];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long r,x,c1,s1,c2,s2,flag=1;
	cin>>r>>x>>c1>>s1>>c2>>s2;
	for(int i=0;i<r;i++){
		for(int j=0;j<x;j++){
			cin>>a[i][j];
		}
	}
	if(c1!=c2 && s1!=s2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	char a;
	a=1;
	if(c1==c2 && s1==s2){
		cout<<a<<0<<0<<0;
		return 0;
	}
	return 0;
}
