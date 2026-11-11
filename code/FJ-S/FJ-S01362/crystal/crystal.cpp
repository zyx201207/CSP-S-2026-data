#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now=1,maxx=0;
	for(int i=2;i<=n;i++){
		m=m-(i-now)*(a[i]-a[i-1]);
		if(m<0){
			while(m<0){
				m=m+a[i]-a[now];
				now++;
			}
		}
		maxx=max(maxx,i-now+1);
	}
	cout<<maxx;
	return 0;
}