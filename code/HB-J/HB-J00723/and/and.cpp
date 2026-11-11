#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool f[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=30;i>=0;i--){
		int lo=pow(2,i);
		int s=0;
		for(int j=1;j<=n;j++){
			if(!f[j])s+=bool(a[j]&lo);

		}

		if(s>=m)sum+=lo;
		if(s>=m)for(int j=1;j<=n;j++)if(!(a[j]&lo))f[j]=1;

	}
	cout<<sum;
	return 0;
}
