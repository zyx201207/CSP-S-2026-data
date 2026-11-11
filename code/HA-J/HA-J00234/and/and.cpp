#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long b[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long k,mm=0,ma=0;;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>mm){
			mm=b[i];
		}
		if(i==1){
			k=b[i];
		}
		k=k&b[i];
		if(k>ma){
			ma=k;
		}
	}
	if(m==n){
		cout<<k;
		return 0;
	}
	if(m==1){
		cout<<mm;
		return 0;
	}
	if(m==2){
		int g=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[i]&b[j]>g){
					g=b[i]&b[j];
				}
			}
		}
		cout<<g;
		return 0;
	}
	cout<<ma;
	return 0;
}
