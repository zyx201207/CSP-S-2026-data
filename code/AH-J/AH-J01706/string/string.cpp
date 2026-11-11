#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,a[200004];
	long long cnt=0;
	char c[200004];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=1,k=n;
	while(j<k&&c[j]!=c[k]){
		if(a[j]>a[k]){
			a[j]=a[j]-a[k];
			cnt+=a[k];
			k--;
		}
		else if(a[k]>a[j]){
			a[k]=a[k]-a[j];
			cnt+=a[j];
			j++;
		}
		else{ 
			j++;k--;
			cnt+=a[j];
		}
	}
	cout<<cnt;
	return 0;
 }
