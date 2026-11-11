#include <bits/stdc++.h>
using namespace std;
long long n,m;//个数，更改次数 
int sum[10000002];//改到该数的全部 更改次数 
int a[10000002];//能量 
int lop[10000002];
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	lop[a[i]]++;
	}
	sort(a+1,a+1+n);
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=(i-1)*(a[i]-a[i-1])+sum[i-1];
	}
	for(int i=1;i<=n;i++){
		if(m>sum[i-1]&&m<sum[i])
		{
			if(lop[a[i]]+(m-sum[i-1])/(a[i]-a[i-1])>=i-1)
			{
				cout<<lop[a[i]]+(m-sum[i-1])/(a[i]-a[i-1]);
			}
			else
			{
				cout<<i-1;
			}
			break;
		}
		else if(m==sum[i]&&sum[i]!=sum[i+1])
		{
			cout<<i;
			break;
		}
	}
	return 0;
} 
