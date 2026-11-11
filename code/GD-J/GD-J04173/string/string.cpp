#include<bits/stdc++.h>
using namespace std;
int n,a[200000],sum;
char c[200000];
string s;
int main(){
	freopen("string.in","r",stdin)
	freopen("String.out","w",stdout)
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<a[i];j++){
    		s[j]=c[i];
		}
	}
	return 0;
}
