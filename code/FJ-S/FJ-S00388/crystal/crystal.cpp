#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],ans=1;
bool pda(){
	long long x=a[1];
	for (int i=1;i<=n;i++){
		if (x!=a[i]) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if (i>=2) b[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	if(pda()){
		cout<<n<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for (int i=2;i<=n;i++){
		long long sum=0,j=i,c=1;
		while (j<=n){
			sum+=c*b[j];
			if (sum>m) break;
			j++,c++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
