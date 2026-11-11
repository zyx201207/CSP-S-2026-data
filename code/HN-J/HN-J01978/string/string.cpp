#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],k;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>1){
			k++;
		}
	}
	if(n==1||k==0){
	}else if(n==2){
		k=min(a[1],a[2]);
	}else{
		k=0;
		for(int i=1;i<=n/2;i++){
			if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1]){
				k+=max(a[i],a[n-i+1]);
			}
		}
	}
	cout<<k;
	return 0;
}
