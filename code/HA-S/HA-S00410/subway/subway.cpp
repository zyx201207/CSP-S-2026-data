#include <bits/stdc++.h>
using namespace std;
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);

int main(){
	long long n,m,a[100001],b[100001],s[100001],sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=(i-1)*a[i]-s[i-1];
		if(b[i]<=m)max(sum,i);
		else if(b[i]>m){
			int t=i;
			while(b[i]>m){
				b[i]-=a[i];
				b[i]+=a[t];
				t--;
			}
		}
	}cout<<sum;
}

cout<<sum;
	return 0;
}
