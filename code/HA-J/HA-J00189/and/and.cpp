#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
unsigned long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		unsigned long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}else{
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((a[i] & a[j])>maxx) maxx=(a[i] & a[j]);
			}
		}
		cout<<maxx;
	}
	return 0;
}
