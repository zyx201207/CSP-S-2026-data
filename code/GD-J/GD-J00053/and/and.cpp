#include <bits/stdc++.h>
using namespace std;

int s_max(int s[], int n){
	int remax = 0;
	for(int i=0;i<n;i++){
		if(s[i]>remax){
			remax=s[i];
		}
	}
	return remax;
}

int main(){ // (3 & 15)=3 
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n,m;
	int s[200000];
	int ot[200000];
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	int cnt=0;
	int a,b;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			a=s[i];
			b=s[j];
			ot[cnt]=(a&b);
		}
	}
	
	cout<<s_max(ot,n);
}
