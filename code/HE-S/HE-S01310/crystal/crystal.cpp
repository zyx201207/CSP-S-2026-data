#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],k=0,c[500010],t=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		k=i-1;
		t=m;
		c[i]=1;
		while(t>0&&k>0){
			if((t-(a[i]-a[k]))>=0){
				t=t-(a[i]-a[k]);
				c[i]++;
			}else{
				break;
			}
			k--;
		}
	}
	sort(c+1,c+n+1);
	cout<<c[n];
	return 0;
}
