#include<bits/stdc++.h>
using namespace std;
int n,x,j,len;
char a,c[900000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		len+=x;
		for(j;j<len;j++){
			c[j]=a;
		}
	}
	int sum=len/2,ans=len/2,j=0;
	for(int i=0,x=len-1;i<sum,x>=ans;i++,x--){
		if(c[i]!=c[x]){
			j++;
		}
	}
	cout<<j;
	return 0;
}
