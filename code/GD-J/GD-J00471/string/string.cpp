#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200007],a1[200007],ans;
char b[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],a1[i]=a[i];
	for(int i=1,j=n;i<=n;i++){
		while(a[i]>=a1[j]&&j>=1){
			if(b[i]!=b[j])
				ans+=a1[j];
			a[i]-=a1[j];
			j--;
		}
		if(b[i]!=b[j])
			ans+=a[i];
		a1[j]-=a[i];
	}
	cout<<ans/2;
	return 0;
}
