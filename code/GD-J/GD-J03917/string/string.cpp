#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],sum[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		int tmp=(c[i]!=c[j]);
		if(a[i]>a[j])
			ans+=a[j]*tmp,
			a[i]-=a[j],
			a[j]=0,
			j--;
		else
			if(a[i]<a[j])
				ans+=a[i]*tmp,
				a[j]-=a[i],
				a[i]=0,
				i++;
			else
				ans+=a[i]*tmp,
				a[i]=a[j]=0,
				i++,j--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
