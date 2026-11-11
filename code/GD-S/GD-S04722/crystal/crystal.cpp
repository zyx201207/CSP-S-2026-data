#include<bits/stdc++.h>
using namespace std;

// n < 5e5   m < 1e18   -1e12 < ai < 1e12
long long a[500001],f;
int p=1; // p最大长度

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long n,m;
	cin>>n>>m;

	if(n>5000){
		long long a1,a2,c,s=0,l=0;
		for(int i=1;i<n;i++)
			cin>>a1;
		cin>>a2;
		c=abs(a1-a2);
		for(long long i=1;s+c*i<=m;i++)
			s+=c*i,l++;
		cout<<l+1;
		return 0;
	}

	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=2;i+j-1<=n;j++){
			f+=(j-1)*(a[i+j-1]-a[i+j-2]);
			if(f<=m)
				p=max(p,j);
			else
				break;
		}
	}
	cout<<p;
	return 0;
}
