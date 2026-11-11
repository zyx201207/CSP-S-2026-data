#include<bits/stdc++.h>
using namespace std;
const int M=1e+6;
int n;                                                                        
long long a[M],z=0,l=0,r,q=0;
char c[M];
string s; 
bool f=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(z<a[i]){
			s[z]=c[i];
			z++;
		}
	}
	r=s.size()-1;
	for(int i=1;i<=s.size()/2;i++){
		if(s[l]!=s[r]){
			q++;
		}
	}
	cout<<q;
	return 0;
}