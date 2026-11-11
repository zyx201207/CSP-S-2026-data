#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin>>n;
	ll a[n+1],s=0;
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
		s+=a[i];
	}
	ll b[s+1],m=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			m+=1;
			b[m]=c[i];
		}
	}
	ll d=0;
	for(int i=1;i<=s/2;i++){
		if(b[i]!=b[s-i+1]){
			d++;
		}
	}
	cout<<d;
}

