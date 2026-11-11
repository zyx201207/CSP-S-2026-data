#include<bits/stdc++.h>
using namespace std;
char a;
string m;
long long n,l=1,r=0,s=0,ant=0,o=1;
long long b; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		s+=b;
		for(int j=o;j<o+b;j++){
			m[j]=a;
		}
		o+=b;
	}
	r=s;
	for(int i=1;i<=s;i++){
		if(r==l||(r-l)==1){
			break;
		}
		if(m[l]!=m[r]){
			ant++;
		}
		l++;
		r--;
	}
	cout<<ant;
	return 0;
	
}




