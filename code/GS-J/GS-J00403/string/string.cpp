#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,a[100005];
char c[200005];
string d="b",b="b";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			d+=c[i];
			b+=c[i];
		}
	}
	for(int i=d.length();i>=0;i--){
		b[d.length()-i]=d[i];
	}
	d+="b";
	for(int i=d.length();i>=0;i--)if(b[i]!=d[i])cnt++;
	cout<<cnt/2;
	return 0;
} 
