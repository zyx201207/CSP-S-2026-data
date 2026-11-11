#include <iostream>
using namespace std;
long long n;
long long m;
long long k;
long long p;
long long s= 100000000000000000;
long long z;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	int a[n],b[n];
	for(int i=1;i <=n;i++){
		cin>>a[i];
		if (i>=n)break;
	}
	for(int i=1;i <=n-2;i++){

		k=a[i+1]-a[i];
		p=a[i+2]-a[i+1];
		b[i] = k;
		if(s>k and s>p){
			if(k>=p)s = p;
			else s = k;
		}

	}
	for(int i=1;m>=0;i++){
		if (i>=n/2+1)break;
		for (int j=i;j<=n/2+1 and m>=0;j++){
			if (m<b[j])break;
			a[i]=a[i]+b[j];
			m=m-b[j];
			z = j;
			
		}
	for (int i=1;i<=n/2+1;i++){
		if (a[z]==a[z+1])z++;
	}
	}
	cout<<z;
	return 0;
}
