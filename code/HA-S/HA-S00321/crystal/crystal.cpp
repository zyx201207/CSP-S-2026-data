#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=1;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long maxxx=1;
		for(int j=i;j>=1;j--){
			if((m-a[i]-a[j])>0){
				m=m-(a[i]-a[j]);
				maxxx+=1;
			}else{
				break;
			}
		}
		maxx=max(maxx,maxxx);
	}
	cout<<maxx;
	return 0;
}
