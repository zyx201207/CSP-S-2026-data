#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		long long maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n);
//	cout<<a[1];
	int andd=a[n];
	int num=1;
	for(int i=n-1;i>=1;i--){
		if(num==m)break;
//		cout<<andd<<' '<<a[i];
		andd=andd&a[i];
		num++;
	}
	cout<<andd;
	return 0;
}
