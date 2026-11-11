#include<bits/stdc++.h>
using namespace std;
long long n,f=0,p=0,q=0;
char a[200005];
long long b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>a[i];
	}
	for(int v=0;v<n-1;v++){
		if(a[v]==a[v+1]){
			q=0;
		}
		else{
			q=1;
		}
	}
	if(q=0){
		cout<<'0';
	}
	else{
		for(int i=0;i<n;i++){
			if(b[i]!=1){
				f=1;
			}
			p+=b[i];
		}
		if(f=0){
			cout<<p/2;
		}
		if(n<=2){
			cout<<min(b[0],b[1]);
		}
	}
	return 0;
}
