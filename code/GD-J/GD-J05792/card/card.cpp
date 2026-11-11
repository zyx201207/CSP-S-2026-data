#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0;
long long a[500005];
long long b[500005];
long long c[500005];
void aa(int u){
	for(int i=u;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				int c=i,d=j;
				while(c<d){
					a[c]=0;
					c++;
				}
			}
		}
	}
	for(int j=u;j<n;j++){
		b[a[j]]++;
	}
	for(int i=0;i<n;i++){
		a[i]=c[i];
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int e=0;e<n;e++){
		aa(e);
	}
	for(int i=1;i<=m;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
	}
	return 0;
} 
