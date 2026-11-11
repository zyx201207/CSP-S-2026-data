#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,pd=1,w;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		if(pd==1){
			sum+=a[i];
			if(sum==m){
				pd=2;
				w=i;
				break;
			}
			if(sum>m){
				pd=3;
				w=i;
				break;
			}
		}
	}
	if(pd==1){
		cout << n;
		return 0;
	}
	if(pd==2){
		if(w==n)cout << n;
		else cout << w+1;
		return 0;
	}
	if(pd==3){
		cout << w;
		return 0;
	}
	return 0;
}
