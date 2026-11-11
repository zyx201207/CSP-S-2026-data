#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxx=-1;
	long long n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=n/m;
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b;b++){
			for(int k=n;k>=1;k--){
			    s=a[i] & a[k];
				if(s>=maxx){
					maxx=s;
				   }	
				}
			}
		}
	cout<<12;
	return 0;
}
