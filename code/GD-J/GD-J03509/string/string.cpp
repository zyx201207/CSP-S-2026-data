#include<bits/stdc++.h>
using namespace std;
int n,cs[200005],sum=0,b=2;
const long long N=2e16+5;
char a[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cs[i]>>a[i];
		for(int j=b;j<i+cs[i];j++){
			a[j]=a[i];
		}
		i=i+cs[i];
		n=n+cs[i];
		b=i+1;
	} 
	for(int i=1;i<=n;i++){
		if(a[1]==a[i]){
			sum++;
		}
	}
	if(sum==n){
		cout<<0;
	}else{
		cout<<n/2;
	}
	return 0;
} 
