#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long n,m;
int a[MAXN]={},b[MAXN]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n]+m;i++){
		int j=1;
		while(a[j]<i){
			
		}
		for(int j=i;j>=a[1];j--){
			
		}
	}
	
	return 0;
}
