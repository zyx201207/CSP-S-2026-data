#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long sum=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n, m, Min=1000000000000000000;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long i;
	long long l=n/2,flag,p=0;
	while(l<=n-1){
		long long temp=m;
		for(long long j=0;j<l;j++){
			s[p]=a[l]-a[j];
			if(temp<=0){
				flag=j+1;
				break;
			}
			temp-=s[p];
			p+=1;
		}
		l+=1;
	}
	i=flag;
	for(long long j=0;j<n;j++){
		if(a[j]==a[i])sum+=1;
	}
	sort(s,s+i);
	for(long long j=0;j<i;j++){
		if(m<=0)break;
		if((m-s[j])>=0&&s[j]>0){
			sum+=1;
			m-=s[j];
		}
	}
	cout<<sum;
	return 0;
} 
