#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int mx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		for(int j=i+1;j<=i+m;j++){
			int s = a[i]&a[j];
			if(s>mx){
				mx=s;
			}
		}
	}
	cout<<mx;
	return 0;
}


