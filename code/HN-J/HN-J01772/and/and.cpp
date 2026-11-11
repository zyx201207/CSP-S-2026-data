#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000000],sum;
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}for (long long i=30;i>=0;i--){
		long long b=0;
		for (long long j=1;j<=n;j++){
			if (((a[j]&sum)==sum) && (a[j]&(1<<i))){
				b++;
				if (b>=m)sum=sum+(1<<i);
			}
		}
	}cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
