#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],f[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//cout<<ans;
	int mini=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		//cout<<f[i]<<endl;
		if((f[i]+m)/i==a[i]) mini=i;
	}
	//cout<<mini;
	int num=0;
	for(int i=n;i>=1;i--){
		long long sum=-1;
		if(a[i]<=a[mini]) sum=a[mini]-a[i];
		//cout<<sum<<endl;
		if(sum!=-1){
			m-=sum;
			if(m>=0) num++;
		}
	}
	//num++;
	cout<<num;
	return 0;
}
//5 5
//1 2 4 8 9

