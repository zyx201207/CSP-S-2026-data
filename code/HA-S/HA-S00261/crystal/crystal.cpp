#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	bool r1=1,r2=1;
	int c;
	cin>>a[1]>>a[2];
	c=a[2]-a[1];
	if(a[1]!=1||a[2]!=2) r1=0;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) r1=0;
		if((a[i]-a[i-1])!=c) r2=0;
	}
	if(r1==1){
		int sum=0;
		for(int i=1,j=m;i<=n&&j>=0;j-=i,i++){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	if(r2==1){
		int sum=0;
		for(int i=1,j=m;i<=n&&j>=0;j-=i*c,i++){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	
	int sum=0,ans=0;
	for(int i=1,j=m;i<=n&&j>=0;j-=(a[2]-a[1])*i,i++){
		ans=i;
		sum++;
	}
	for(int i=ans+1;i<=n;i++){
		if(a[i]!=a[ans]){
			break;
		}
		sum++;
	}
	cout<<sum;
	return 0;
}
