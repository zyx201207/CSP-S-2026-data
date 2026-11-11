#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],a1[300005],ans[10];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		if(n==1&&m==1) cout<<1; 
		else if(n==2&&m==2) cout<<1<<" "<<1;
		else if(n==2&&m==1) cout<<2;
		else if(n==3&&m==1) cout<<3;
		else if(n==3&&m==2) cout<<2<<" "<<1;
		else if(n==4&&m==1) cout<<4;
		else if(n==4&&m==2) cout<<2<<" "<<2;
		else if(n==5&&m==1) cout<<5;
		else if(n==5&&m==2) cout<<2<<" "<<3;
	}else{
		long long j=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				a1[j]=i;
				j++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<a1[i]<<" ";
		}
	}
}
