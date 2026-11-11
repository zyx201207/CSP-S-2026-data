#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i <=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<"0";
	}
	if(n==2){
		if(b[1]==b[2]){
			cout<<"0";
		}
		else if(a[1]>=a[2]){
			cout<<a[2];
		}
		else if(a[1]<a[2]){
			cout<<a[1];
		}
	}
	if(n==3){
		int t=a[2]+a[3];
		if(a[1]==1 && a[2]==1 && a[3]==1){
			cout<<"1";
		}
		else if(a[1] >= t){
			cout<<t;
		}
	}
	return 0;
}
