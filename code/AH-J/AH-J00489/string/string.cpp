#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005],sum;
char c[500005],d[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	long long i=1,j=1;
	while(i!=n+1&&j!=n+1){
		long long tmp=min(a[i],b[j]);
		if(c[i]==d[j]){
			a[i]-=tmp;
			b[j]-=tmp;
			if(a[i]==0) i++;
			if(b[j]==0) j++;
		}else{
			sum+=tmp;
			a[i]-=tmp;
			b[j]-=tmp;
			if(a[i]==0) i++;
			if(b[j]==0) j++;
		}
	}
	cout<<sum/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
