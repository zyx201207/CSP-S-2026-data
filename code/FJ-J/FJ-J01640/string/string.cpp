#include<bits/stdc++.h>
using namespace std;
int n;
int s[200005];
char c[200005],b[50000005];
int a=0;
int p=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>s[i]>>c[i];
    for(int j=1+a;j<=a+s[i];j++){
    b[j]=c[i];
	} 
	a+=s[i];
	}
    for(int i=1;i<=a/2;i++){
    if(b[i]==b[a-i+1])p++;
	}
    cout<<a/2-p;
	return 0;
} 
