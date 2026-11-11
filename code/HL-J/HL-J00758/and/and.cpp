#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],q,o;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			q=q&a[i];
		}
	}
	else if(m==1){
		q=0;
		for(int i=1;i<=n;i++){
			if(a[i]>q){
				q=a[i];
			}
		}
	}
	else if(m==2){
		q=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>q){
					q=a[i]&a[j];
				}
				
			}
		}
	}
	else{
		q=a[n];
	}
	cout<<q;
	return 0;
}