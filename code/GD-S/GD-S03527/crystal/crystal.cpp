#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans,ab;
bool AB=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (i==2) ab=a[i]-a[i-1];
		else if (a[i]-a[i-1]!=ab && AB) AB=0;
	}
	if (AB){
		for (int i=1;i<=n;i++){
			m-=ab*(i-1);
			if (m<0){
				cout << i-1;
				return 0;
			}else if (m==0){
				cout << i;
				return 0;
			}
	 }
	}
	sort(a+1,a+1+n);
	bool flag=0;
	for (int i=2;i<=n;i++){
		int cnt=0,num=m;
		for (int j=i-1;j>0;j--){
			if (a[i]-a[j]>num){
				flag=1;
				break;
			}else{
				num-=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt+1);
		if (flag) break;
	}
	cout << ans;
	return 0;
}
