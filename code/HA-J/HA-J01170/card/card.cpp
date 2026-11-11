#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
long long n,m;
int a[M];
long long d[2];
int b=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];	
	}
	b=a[1];
	if(m<=2){
		for(int i=1;i<=n;++i){
			if(a[i]==a[n]) {
				if(a[i]==b) d[1]++;
				else d[2]++;
			}
			else{
				d[1]++;d[2]++;
			}
		}	
		cout<<d[1]<<' '<<d[2];
		return 0;
	}
	for(int i=1;i<=n;++i){
		cout<<1<<' ';
	}
	return 0;
}
