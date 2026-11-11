#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,pjz=0,flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pjz+=a[i];
	}
	pjz=pjz/n;
	long long cha[n+5];
	for(int i=1;i<=n;i++){
		cha[i]=abs(a[i]-pjz);
		if(cha[i]<cha[i-1]){
			flag=a[i];
		}else continue;
	}
	long long cha_flag[n+5];
	for(int i=1;i<=n;i++){
		if(a[i]<=flag){
			cha_flag[i]=flag-a[i];
			ans++;
		}else continue;
	}
	cout<<ans;
	return 0;
}
