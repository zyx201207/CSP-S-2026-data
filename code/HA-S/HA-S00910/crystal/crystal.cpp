#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int L,R;
int a[1000000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	L=1;R=n;
	for(int i=1;i<=n;i++){
		if(a[L]+m>=a[R]){
			a[0]=a[R]-a[L];
			a[L]+=a[0];
			m-=a[0];
			L++;
		}
		else R--;
	}
	a[0]=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[R])ans++;
	}
	cout<<ans;
	return 0;
} 
