#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum;
char b[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n/2;j++){
			if(b[i]!=b[n-j+1]&&a[i]>a[n-i+1]){
			   sum+=a[n-i+1];
			   a[i]-=a[n-i+1];
		}
			if(b[i]!=b[n-j+1]&&a[i]<=a[n-i+1]){
				sum+=a[i];
				break;
			}
	}
}
	cout<<sum;
	return 0;
}
