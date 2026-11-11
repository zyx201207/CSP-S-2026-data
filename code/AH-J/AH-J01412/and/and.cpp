#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=l+m-1;
	while(r<=n){
		int p=a[l];
		for(int i=l+1;i<=r;i++){
			p&=a[i];
		}
		maxn=max(maxn,p);
		l++;
		r++;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
