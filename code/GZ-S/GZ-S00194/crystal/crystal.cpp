//GZ-S00194 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
long long m,k;
long long a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ma=0;
	k=m;
	for(int i=2;i<=n;i++){//模拟最大值 
		m=k;
		int cnt=1;
		for(int j=i-1;j>=1;j--){//由假设最大值向前搜 
			long long t=a[i]-a[j];
			if(t<=m){
				m-=t;
				cnt++;
			}
		}
		ma=max(ma,cnt);
	}	
	cout<<ma;
	return 0;
}
