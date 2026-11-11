#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int f1=0;
	if(c1==c2){
		f1=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	int f2=0;
	if(f1==1 && s1[0]==s2[0] && s1[1]==s2[1]){
		f2=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	char l1=s1[2],l2=s2[2];
	int f3=0;
	if(f1==1 && f2==1 && ((l1>='A' && l1<='C' && l2>='A' && l2<='C') || ((l1=='D' || l1=='F') && (l2=='D' || l2=='F')))){
		f3=1;
		cout<<1;
	}
	else{
		cout<<0; 
	}
	if(f3==1 && f2==1 && f1==1){
		if(l1==l2+1 || l1==l2-1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
