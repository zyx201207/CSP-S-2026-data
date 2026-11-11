#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
int n,ans=-1e9;
long long m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int j=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		while(b[i]-b[j]-(a[i]-a[j])*j>m){
			j++;
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

