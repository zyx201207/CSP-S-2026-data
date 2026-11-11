#include<bits/stdc++.h>
using namespace std;
int x(string n,int k){
	for(int i=0;i<k;i++){
		if(n[i]!=n[k-1-i])
		return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,c,f;
	string s,z;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>s;
		f=b+f;
		for(int j=1;j<=b;j++){
			z=z+s;
		}
	}
	for(int i=0;i<f;i++){
		if(x(z,f)){
			cout<<c;
			break;
		}
		c++; 
	}
	fclose(stdin);
	fclose(stdout);
}
