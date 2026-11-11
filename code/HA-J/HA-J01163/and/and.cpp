#include <bits/stdc++.h>
long long n,m,sum=0;
long long a[10000001];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m=1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>a[i-1])
				sum=a[i];
		}
		cout<<sum;
	}
	else if(m=n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum&=a[i];
		}
		cout<<sum;
    }
	return 0;
}
