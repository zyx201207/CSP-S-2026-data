#include<bits/stdc++.h>
using namespace std;
int n,s;
long long k;
long long a[500010];
long long h;
int l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	int i=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		h+=(a[i]-a[i-1])*(i-l);
		while(h>k){
			h-=a[i]-a[l];
			l++;
		}
		s=max(s,i-l+1);
	}
	cout<<s;
	return 0;
}
