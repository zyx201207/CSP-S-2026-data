#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,t,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		t=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	cnt=m/t;
	long long sum=1,sum1=1;
	while(true){
		sum1++;
		if(sum>cnt){
			break;
		}
		sum+=sum1;
	}
	cout<<sum1-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
