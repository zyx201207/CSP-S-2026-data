#include<bits/stdc++.h>
using namespace std;
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a;string f;cin>>a>>f;
		for(int i=1;i<=a;i++)x+=f;
	}string reversed;
	for(int i=x.size()-1;i>-1;i--)
		reversed+=x[i];
	if(x==reversed){cout<<0;return 0;}
	if(x.size()==1){cout<<0;return 0;}
	if(x.size()==2){
		if(x[0]==x[1])cout<<0;
		else cout<<1;
		return 0;
	}string index=x;
	int mid=(x.size()%2==0?(x.size()/2):(x.size()/2+1));
	for(int i=mid;i<x.size();i++)x[i]=reversed[i];
	int wrong=0;
	for(int i=0;i<x.size();i++)if(index[i]!=x[i])wrong++;
	cout<<wrong;
	return 0;
}

