#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+9; 
long long n,m,a[maxn],sum[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(n==1){
		cout <<1<<endl;
		return 0;
	}else if(n==2){
		long long a,b;
		cin >> a >> b;
		if(abs(a-b)<=m)cout <<2;
		else cout <<1<<endl;
		return 0;
	}
	long long ans=0;
	int flag=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	    if(i!=2&&sum[i]!=sum[i-1])flag=1;
	}
	if(flag==0){
		long long i=1;
		while(i*(i+1)*sum[3]<=(m<<1)&&i<=n){
			i++;
		}
		if(i<=n)cout <<i<<endl;
		else cout <<n;
	}
	return 0;
}   
