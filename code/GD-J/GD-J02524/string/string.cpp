#include<bits/stdc++.h>
using namespace std;
string a="";
int s;
long long d,l;
char c;
int main(){
    freopen("string.in ","r",stdin);
    freopen("string.out ","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>s>>c;
		for(int j=1;j<=s;j++)a+=c;
		d+=s;
	}
	for(long long i=0;i<=ceil(d/2);i++){
		if(a[i]!=a[d-i-1])l++;
	}
	cout<<l<<endl;
    return 0;
}
