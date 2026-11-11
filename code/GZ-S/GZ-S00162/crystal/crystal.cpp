//GZ-S00162 兴义市弘毅中学 付新峻羽
#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=INT_MIN,sum;
long long a[500005];
long long qianzhui[500005];
long long b[101];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		qianzhui[i]=qianzhui[i-1]+a[i];
	}
	for(long long i = 1;i<=n;i++){
		for(long long j=0;j<i;j++){
			sum=a[i]*(i-j)+qianzhui[j]-qianzhui[i];
			if(sum<=m){
				if(i-j>maxx){
					maxx=i-j;
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
