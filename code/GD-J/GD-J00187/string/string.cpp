#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int b;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i].b>>a[i].c;
	for(int i=1,j=n;i<=n,j>i;i++,j--){
		if(a[i].c!=a[j].c)sum+=min(a[i].b,a[j].b);
		if(a[i].b>a[j].b){
			a[i].b-=a[j].b;
			i--;
		}
		else if(a[i].b<a[j].b){
			a[j].b-=a[i].b;
			j++;
		}
	}
	cout<<sum;
	return 0;
}
