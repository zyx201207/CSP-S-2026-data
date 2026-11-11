#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,m1,sum=0,cnt=0,t=0;
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		m1=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m1){
				sum++;
				m1=m1-a[i]+a[j];
			}
			t++;
		}
		cnt=max(cnt,sum);
		sum=0;
		if(t>=90000000){
			cout<<cnt+1;
			break;
		}
	}
	cout<<cnt+1;
} 
