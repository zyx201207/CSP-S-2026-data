#include<bits/stdc++.h>
using namespace std;
int a[600050],o;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,u;
	cin>>n>>m;
	int r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r+=a[i];
	}
	u=r/n;	
	for(int i=1;i<=u+2;i++){
		int p=0;
		for(int j=1;j<=n;j++){
			if(a[j]<i){
				p+=i-a[j];
			}
		}
		if(p>m){
			o=i-1;
			break;
		} 
		if(p==m){
			o=i;
			break;
		}
	}
	int l=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=o){
			l++;
		}
	}
	cout<<l;
	return 0;
}

 
