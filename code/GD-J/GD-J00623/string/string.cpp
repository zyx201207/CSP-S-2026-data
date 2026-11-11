#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sum,s1[200005],s2[200005];
int flg[200005];
char chr[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		flg[i]=a;
		s1[i]=s1[i-1]+flg[i];
		chr[i]=c;
		sum+=a;
	}
	for (int i=n;i>=1;i--){
		s2[i]=s2[i+1]+flg[i];
	}
	int l=1,r=n,i=1,j=sum;
	while (i<=j){
		if (i>s1[l]){
			l++;
		}if (sum-j+1>s2[r]){
			r--;
		}
		char dq=chr[l];
		char dh=chr[r];
		if (dq!=dh){
			ans++;
		}
		i++;j--;
	}
	cout << ans;
	return 0;
}
