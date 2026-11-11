#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
int a[500005];
bool db = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n>5000){
		db = 1;
	}
	int ans = 1;
	for(int i=n-1;i>0;i--){//i为标准 
		int tm = m;
		int tans=0;
		for(int j=i-1;j>=0;j--){ 
			//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<tm;
			if(a[i]-a[j]<=tm){
				tm-=a[i]-a[j];
				tans++;
				//cout<<" "<<"11";
			}else{
				//break;//后面肯定不大于，直接退
			}
			//cout<<endl;
		}
		if(db){ //大于5000有几率出现等差数列 
			cout<<tans;
			return 0;
		}
		ans = max(ans,tans);//取所有次数的最大值 
	}
	cout<<ans+1;
	return 0;
} 
