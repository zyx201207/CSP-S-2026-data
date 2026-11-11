#include<bits/stdc++.h>
using namespace std;
int n,k,f;
char b[200005];
struct s{
	int c;
	char s;
}a[200005];
bool s(int n){
	for(int i=0;i<n;i++){
		if(b[i]!=b[n-i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
	}
	for(int i=1;i<=n;i++){
		while(a[i].c--){
			b[f]=a[i].s;
			f++;
		}
	}
	if(s(f)==1){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].s!=a[j].s){
				k=1;
			}
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
