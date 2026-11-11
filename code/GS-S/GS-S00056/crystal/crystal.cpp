#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flag1=1;//A
	bool flag2=1;//B
	long long temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			temp=a[2]-a[1];
		}
		if(i>=2){
			if(a[i]!=a[i-1]){
				flag1=0;
			}
			if(a[i]-a[i-1]!=temp){
				flag2=0;
			}
		}
	}
	//cout<<flag1<<' '<<flag2<<'\n';
	if(flag1==1){
		cout<<n;
	}
	else if(flag2==1){
		if(m/temp<n) cout<<m/temp;
		else cout<<n;
	}
	else{
		cout<<n;
	}
	return 0;
} //30pts
//rp++
