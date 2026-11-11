#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],maxn,e[500005],dt;
bool flag=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(n>5000){
		cin >> a[1] >> a[2];
		dt=a[2]-a[1];
		for(long long i=3;i<=n;i++){
			cin >> a[i];
			if(a[i]-a[i-1]!=dt) flag=0;
		}
		if(flag){
			sort(a+1,a+n+1);
			dt=abs(dt);
			for(long long i=1;i<n;i++){
				b[i+1]=i+b[i];
			}
			for(long long i=n;i>1;i--){
				if(b[i]*dt<=m){
					cout << i;
					break;
				}
			}
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}else{
		for(long long i=1;i<=n;i++){
			cin >> a[i];
			if(a[i]!=i) flag=0;
		}
	}
	
	
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j>1;j--){
			c[i]+=(j-1)*b[j];
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			
			if((c[j]-c[i]-(i-1)*(a[j]-a[i]))<=m){
				maxn=max(maxn,j-i+1);
			}
		}
	}
	
	cout << maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
