#include<bits/stdc++.h>
using namespace std;

int n,m,a[50005],sum=1,cnt=2,k;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	while(m>0){
		k=a[sum];
		m=m-(k-a[sum-1])*sum;
		sum++;
		cnt++;
	}
	for(int i=sum;i<n;i++){
		if(a[sum]==a[sum+1])
			cnt++;
		else
			break;
	}
	cnt--;
	cout<<cnt;
	return 0;
}
