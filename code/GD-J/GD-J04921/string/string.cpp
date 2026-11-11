#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,ans=0,a,x=0,z=0;
	char b,s[200005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int z=x;
		for(int j=z;j<a+z;j++){
			s[j]=b;
			x=j;
		}
	}
	for(int i=0;i<x;i++){
		cout<<s[i];
	}
	for(int i=0,j=x;j>=i;i++,j--){
		if(s[i]!=s[j]){
			ans++; 
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
