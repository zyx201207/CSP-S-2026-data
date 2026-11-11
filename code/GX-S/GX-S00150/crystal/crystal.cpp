#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[n+1];
	b[n]=0;
	for (int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int da=0;
	for (int i=1;i<n;i++){
		int ca=0;
		for (int j=i;j<n;j++){
			int w=j-i+1;
			ca+=b[j]*w;
			if (ca>m){
				if (w-1>da){
					da=w-1;
				}
				break;
			}
		}
	}
	cout<<da+1;
	return 0;
}
