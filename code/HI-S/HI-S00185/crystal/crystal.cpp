#include<bits/stdc++.h>
using namespace std;
long long n,q,a[500005],b[500005],sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i-1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		b[i]*=i;
	}
	for(int i=1;i<=n-1;i++){
		q+=b[i];
		if(q<0){
			break;
		}
		sum++;
	}
	cout<<++sum;
	return 0;
}

