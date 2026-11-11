#include<bits/stdc++.h>
using namespace std;
int n,a,n1=0,n2=0;
char c,d[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=n1+1;j<=n1+a;j++)
		d[j]=c;
		n1+=a;	
		
	}
	for(int i=1;i<=n1/2;i++){
		if(d[i]!=d[n1-i+1])
		n2++;
	}
	cout<<n2;
		return 0;
}
