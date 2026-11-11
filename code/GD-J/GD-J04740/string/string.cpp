#include<bits/stdc++.h>
using namespace std;
int n,s[200005],m,k,j;
string a,q[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>q[i];
		m+=s[i];
		for(int h=0;h<s[i];h++){
			a+=q[i];
		}
	}
	k=m-1;
	for(int i=0;i<m/2;i++){
		if(a[i]!=a[k]){
			j++;
		}k--;
	}
	cout<<j;
}
