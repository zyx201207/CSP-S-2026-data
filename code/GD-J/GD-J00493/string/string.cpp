#include<bits/stdc++.h>
using namespace std;
long long a[26]={};
string s,z;
long long lenz,i,num;
int n,x,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>s; 
		a[s[0]-'a']+=x;
		for(j=0;j<x;j++){
			z+=s;
		}
	}
	lenz = z.length();
	for(i=0;i<lenz/2;i++){
		if(z[i]!=z[lenz-i-1]){
			if(a[z[i]-'a']>=a[z[lenz-i-1]]){
				num++;
			}else{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

