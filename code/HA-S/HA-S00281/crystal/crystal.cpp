#include<bits/stdc++.h>
using namespace std;
int length;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	int need=0;
	for(;r<=n;){
		if(need<=m){
			length=max(length,r-l+1);
			r++;
			need+=(a[r]-a[r-1])*(r-l);
		}
		else {
			l++;
			need-=(a[r]-a[l]);
		}
	}
	cout<<length<<endl;
	return 0;
}
