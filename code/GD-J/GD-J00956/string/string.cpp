#include<bits/stdc++.h>
using namespace std;
long long n,num,an,sn[30],sumn;
char al;
int main(){
	freopen("string.in","r",stdin);///////////////
	freopen("string.out","w",stdout);/////////////
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>al;
		sn[al-'0']+=num;
	}
	for(int i=1;i<=26;i++){
		if(sn[i]){
			an++;
			sumn+=sn[i];
		}
	}
	if(an==1){
		cout<<0;
		return 0;
	}
	if(an==2){
		cout<<sumn/2;
		return 0;
	}
	cout<<sumn;
} 
