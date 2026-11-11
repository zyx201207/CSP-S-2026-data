#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n,m,a[500010]={},cf[500010]={},sum=0,ss=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool tp1=1,tp2=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=i) tp1=0;
		if (i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) tp2=0;
	}
	if (tp1){
		int i=0;
		while (i*i-i*(i+1)/2<=m&&i<=n) i++;
		cout<<i-1;
		return 0;
	}
	if (tp2){
		int i=0;
		while (a[i]*i-(a[1]+a[i])*i/2-(i%2==1?a[i/2+1]:0)<=m&&i<=n) i++;
		cout<<i-1;
		return 0;
	}
	sort(a+1,a+1+n);
	int mina=a[1];
	for (int i=1;i<=n;i++){
		a[i]-=mina;
	}
	cf[1]=a[1];
	for (int i=2;i<=n;i++){
		cf[i]=cf[i-1]-a[i];
		//cout<<cf[i]<<" "<<i<<" "<<a[i]<<endl;
	}
	for (int i=1;i<=n;i++){
		sum=0;
		for (int j=i;j<=n;j++){
			//cout<<-cf[j]+cf[i-1]<<" "<<a[j]<<" "<<cf[j]<<" "<<cf[i-1]<<" "<<j<<endl;
			//_sleep(100000);
			if (-cf[j]+cf[i-1]>m){
				sum=1ll*j-i;
				j--;
				int aw=0;
				do{aw++;/*cout<<a[j+aw]<<" "<<a[j]<<" "<<j<<endl;*/}while(a[aw+j]==a[j]&&aw+j<=n);
				sum+=aw-1;
				//cout<<sum<<endl;
				break;
				
			}
		}
		//_sleep(100000);
		if (sum==0) sum=n-i+1;
		ss=max(sum,ss);
		//cout<<endl;
	}
	cout<<ss;
	return 0;
} 
/*
6 
1
*/
