#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000000];
char b[2000000];
long long z;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}   
	for(int i=1;i<=s.length();i++){
		if(a[i]!=a[n-i+1]){
			z++;
		}
	}
	cout<<z;
}
