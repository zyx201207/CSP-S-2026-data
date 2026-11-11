#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
string a,b;
ll step1,n,m;
int hui_wen(string a){
	int k=0;
	for(ll i=0;i<a.size()/2;i++){
		if(a[a.size()-i-1]!=a[i]){
			k++;
		}
	}
	if(k==0){
		return 1;
	}
	else{
		return k;
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>m>>b;
		for(int i=1;i<=m;i++) a+=b;
	}
	step1=hui_wen(a);
	if(step1==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else{
		cout<<step1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
