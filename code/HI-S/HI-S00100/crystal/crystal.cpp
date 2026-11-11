#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long in[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}
	long long num=in[2]-in[1],sum=m;
	for(int i=1;i<=m/num+1;i++){
		sum-=(num*i);
		if(sum<0){
			break;
		}else{
			cnt++;
		}
	}
	cout<<cnt+1;
	return 0;
} 
