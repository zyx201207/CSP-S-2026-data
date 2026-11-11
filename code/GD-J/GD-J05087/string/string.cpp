#include<bits/stdc++.h> 
using namespace std;
long long b=0,n,cnt=0,c,i=0,d=1;
int a[1000000005];
char x[1000000005];
char y[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>x[i];
		for(int j=b;j<b+a[i];j++){
			y[j]=x[i];
		}
		b+=a[i];
	}
	for(int i=0;i<b/2;i++){
		if(y[i]!=y[b-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
