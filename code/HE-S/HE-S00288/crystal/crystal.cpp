#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],pref[500005],diff[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=1;
	pref[1]=a[2]-a[1];
	diff[1]=pref[1];
	for(int i=2;i<=n;i++){
		int sum=(a[i+1]-a[i])*i;
		pref[i]=sum+pref[i-1];
		diff[i]=(sum/i);
		diff[i-1]+=(sum/i);
		diff[i-2]+=(sum/i);
		cnt++;
		if(pref[i]>m){
			pref[i]-=diff[i-2];
			diff[i-2]=0;
			cnt--;
		}
		}
	cout<<cnt;
	return 0;
}

 


