#include <bits/stdc++.h>
using namespace std;
long long n,s=0;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1){
			if(a[i]!=a[i-1]){
				f=false;
			}
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n==2){
		if(c[1]==c[2])cout<<0;
		else cout<<min(a[1],a[2]);
		return 0;
	}
	else if(f==true){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n+1-i])s++;
		}
		cout<<s*a[1];
		return 0;
	}
	return 0;
}
