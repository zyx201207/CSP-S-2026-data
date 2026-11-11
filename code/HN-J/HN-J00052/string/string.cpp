#include<bits/stdc++.h>
using namespace std;
int const con=2e5+10;
struct jgt{
	int o;
	string e;
}a[con];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,x=0,y=0;
	string s,s1; 
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].o>>a[i].e;
		x+=a[i].o;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<a[i].o; j++){
			s=s+a[i].e;
		}
	}
	s1=s;
	if(x/2*2==x){
		x=x/2;
	}
	else{
		x=x/2+1;
	}
	for(int i=0,j=x-1; i<x,j>=0; i++,j--){
		if(s[i]!=s1[j]){
			s1[j]=s[i];
			y++;
		}
	}
	cout<<y;
	return 0;
} 
