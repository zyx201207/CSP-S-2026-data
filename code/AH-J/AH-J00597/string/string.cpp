#include<bits/stdc++.h>
using namespace std;
int n,sum,x=1;
long long a[200005];
char c[200005];
string s[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[x]=c[i];
			x++;
		}
	}
	for(int i=1;i<=x-1;i++){
		if(s[i]!=s[x-i])sum++;
	}
	cout<<sum;
}
