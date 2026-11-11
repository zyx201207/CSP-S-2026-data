#include <bits/stdc++.h>
using namespace std;
long long n,m,ci;
long long a[999999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=m;i++){
		long long ge=0,x;
		ci=0;
		for(long long j=1;j<=n;j++){
			if(a[j]==i){
				x=j;
				break;
			}
		}
		for(long long j=1;j<=n;j++){
			if(a[j]==i){
				ge++;
			}
		}
		if(ge%2==1){
			ci=ci+x;
			ci=ci+ge/2;
		}
		else{
			ci=ci+ge/2;
		}
		cout<<ci<<" ";
	}
	
	return 0;
}
