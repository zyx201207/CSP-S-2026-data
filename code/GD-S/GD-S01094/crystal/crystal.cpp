#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		long long h=m;
		long long s=1;
		long long z=j;
		while(z<=n-1){	
			long long o=a[z+1]-a[z];
			if(o*s<=h){
				h-=o*s;
				s++;
				z++;
			}else{
				break;
			}
		}
		for(long long i=z+1;i<=n;i++){
			if(a[i]==a[z]) s++;
		}
		if(ans<s) ans=s;
	}
	cout<<ans;
	return 0;
}
