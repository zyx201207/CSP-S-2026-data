#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,k=0,a[200000],b[20000]={0};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=20000;i>=1;i--){
		while(b[i]!=0){
			k++;
			if(k==m){
				cout<<i;
				return 0;
			}
			b[i]--;
		}
	}
	return 0;
}
