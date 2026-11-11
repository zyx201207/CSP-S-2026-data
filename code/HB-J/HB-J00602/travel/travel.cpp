#include<bits/stdc++.h>
using namespace std;
string n1,m1,n2,m2,m11,m22,m111,m222;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>n1>>m1>>n2>>m2;
	if(n1==n2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		m11+=m1[i];
		m22+=m2[i];
	}
	if(m11==m22){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
		m111=m1[2];
		m222=m2[2];
		if(m111=="A" and m222=="B" or m111=="B" and m222=="A" or m111=="C" and m222=="D" or m111=="C" and m222=="E" or m111=="D" and m222=="C" or m111=="D" and m222=="E" or m111=="E" and m222=="C" or m111=="E" and m222=="D"){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
		if(m111=="A" and m222=="B" or m111=="B" and m222=="A" or m111=="C" and m222=="D" or m111=="D" and m222=="C" or m111=="D" and m222=="E" or m111=="E" and m222=="D"){
			cout<<1;
		}else{
			cout<<0;
		}
	return 0;
}
