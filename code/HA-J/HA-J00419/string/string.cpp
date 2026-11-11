#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	long long num1=0,zong=0,r[26]={};
	string se;
	cin>>n;
	for(int i=0;i<n;i++){
		long long f;
		char e;
		cin>>f>>e;
		zong+=f;
		se+=f*e;
		r[e-'a']+=f;
	}
	for(long long i=0;i<zong/2;i++){
		if(se[i]!=se[zong/2+i])	{
			num1+=1;
			
		}
		
		
	}
	cout<<num1;
	
	cout<<"\n";
	return 0;
}
