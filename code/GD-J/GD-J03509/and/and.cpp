#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,a[N],cs=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(m=1){
			cout<<a[i];
			return 0;
		}
		if(m==2&&a[i]==a[i-1]){
			cout<<a[i];
			return 0;
		}else{
			cout<<a[i-1];
		} 
		if(m==3&&a[i]==a[i-1]&&a[i-1]==a[i-2]){
			cout<<a[i];
			return 0;
		}else{
			cout<<a[3];
			return 0;
		}
		for(int j=1;j<=m;j++){
			if(a[i]==a[i-j]){
				cs++;
			}
		}
		if(cs==m){
			cout<<a[m];
			return 0;
		}else{
			if(cs==m-1){
				cout<<a[m];
			} 
		}
			
		}
	return 0;
} 
