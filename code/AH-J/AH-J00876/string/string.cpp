#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001],c=0,b=0;
char s[200001],s1[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
	    cin>>a[i]>>s[i];
	    for(int j=b;j<=a[i]+b-1;j++)s1[j]=s[i];
	 	b+=a[i];
	}
	for(int i=0;i<b/2;i++){
	    if(s1[i]!=s1[b-1-i])c++;	
	}
	cout<<c;
    return 0;
}
