#include<bits/stdc++.h>
using namespace std;
char b[100000000],c[600000000];
int n,a[100000000],nnn;
long long k=0,m=0,d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
    d+=a[i];
    for(int j=1;j<=a[i];j++){
    	k++;
    	c[k]=b[i];
	}
    }
    int l=1,r=d;
    while(r>=l){
    	if(c[r]!=c[l])m++;
    	r--;
    	l++;
	}
	cout<<m;
    return 0;
}
