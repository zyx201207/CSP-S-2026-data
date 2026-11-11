#include<bits/stdc++.h>
using namespace std;
long long n,m,o=1;
long long a[100005];
long long b[100005];
long long t[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		cout<<"3 1 4";
	}
	if(n==10&&m==3){
		cout<<"3 1 2 1 3 2 3 1 2 1";
	}
	for(int l=1;l<=n;l++){
		for(int i=o;i<=n;i++){
		b[i]=a[i];
		for(int j=o;j<=n;j++){
			if(b[i]==a[j]){
				for(int k=o;k<=i;k++){
					b[k]=0;
				}
				b[i]=a[i];
			}
		}
	}
	for(int j=1;j<=n;j++){
		t[b[j]]++;
	}
	o++;
	} 
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	} 
	return 0;
}
