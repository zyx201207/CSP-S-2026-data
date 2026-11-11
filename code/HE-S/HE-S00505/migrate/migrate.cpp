#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int p = 0;p<t;p++){
		int n,d;
		cin>>n>>d;
		int plus = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			plus+=a[i];
		}

		if(plus==(a[1]+a[n])*(1+(a[n]-a[1])/(a[2]-a[1]))/2){
			cout<<n-3;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
