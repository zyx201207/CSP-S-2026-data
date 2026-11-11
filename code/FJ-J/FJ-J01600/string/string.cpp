#include<bits/stdc++.h>
using namespace std;
long long n,i,a[20010],num[20010],b[50000010],ff;
char c[20010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ff=a[1];
	for(i=1;i<=n;i++){
		ff=__gcd(ff,a[i]);
	}
	for(i=1;i<=n;i++){
		a[i]/=ff;
		num[i]=num[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[num[i-1]+j]=c[i]-'a'+1;
		}
	}
	int ans=0;
	for(i=1;i<=(num[n]/2);i++){
		if(b[i]!=b[num[n]-i+1]){
			ans++;
		}
	}
	cout<<ans*ff; 
	return 0;
}

