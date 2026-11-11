#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n=0;
long long e,f,g;
long long a[N],b[N];
char c[N],d[N];
string s,z;
	int j=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<a[i];j++){
			z+=c[i];
		}
	}
	for(int i=0;i<z.size();i++){
		if(z[i]!=s[i]){
			e++;
		}
	}
	cout<<e/2;
	return 0;
}

