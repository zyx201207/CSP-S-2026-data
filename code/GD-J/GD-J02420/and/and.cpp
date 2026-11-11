#include <bits/stdc++.h>
using namespace std;
int est;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]&s[j]>est){
				est=s[i]&s[j];
			}
		}
	}
	if(m==1){
		est=0;
		for(int i=1;i<=n;i++){
			if(s[i]>est){
				est=s[i];
			}
		} 
	}
	if(m==n){
		est=0;
		for(int i=1;i<=n;i++){
			est=est&s[i];
		} 
	}
	cout<<est;
	return 0;
} 
