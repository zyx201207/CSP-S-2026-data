//GZ-S00397 毕节梁才学校 王艺杰
#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],d[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	long long cnt=0;
	int i;
	int ma=0,st=1;
	for (i=1; i<=n; i++){
		d[i]=a[i]-a[i-1];
		if (cnt+(i-st)*d[i]<=m){
			cnt+=(i-st)*d[i];
		}else{
			ma=max(ma,i-st);
			cnt-=min(a[i-1]-a[st],m);
			st++;
		}
	}
	cout << ma<<endl;
	return 0;
}
