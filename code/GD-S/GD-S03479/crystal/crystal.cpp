#include<bits/stdc++.h> 
using namespace std;
int n,ans,yo;
long long k=0,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
		k=k+a[i];
	}
	k=(k+m)/(n+1);
	for(int i=0;i<n/2+1;i++)
		for(int j=0;j<n;j++){
			if(a[j]>a[j+1]){
				int c;
				c=a[j+1];
				a[j+1]=a[j];
				a[j]=c;
			}
		}
	for(int i=0;i<n;i++){
		if(a[i]<=k)
		yo++;
	}
		/*if(m>=yo)k++;
	for(int i=0;i<n;i++){
		if(a[i]<k)
		yo++;
		m=m-k+a[i];
	}
	/*for(int i=0;i<n;i++){
		cout<<a[i];
	}*/
	cout<<yo;
}
