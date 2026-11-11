#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],z[500005],f[500005],_max=-0x3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		z[i]=z[i-1];
		f[i]=f[i-1];
		if(a[i]>=0) z[i]+=a[i];
		else f[i]+=a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=n;i>0;i--){
			long long goal=a[i],need=goal*(i-1)-z[i-1]-f[i-1];
			if(m>=need){
				if(i>_max) _max=i;
			}
		}
	}
	cout<<_max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
