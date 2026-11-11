#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxn;
bool check(int x){
	int cnt = 0;
	for(int i=1;i<=n;i++)
		if((a[i]&x)==x) cnt++;
	if(cnt>=m) return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i],maxn = max(maxn,a[i]);
	sort(a+1,a+1+n);
	if(n<=10000){
		for(int i=n;i>=1;i--)
			if(check(a[i])){
				cout << a[i];
				break;
			}
		return 0;
	}else if(maxn<=2000){
		for(int i=maxn;i>=0;i--)
			if(check(i)){
				cout << i;
				break;
			}
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(a[mid])){
			l = mid+1;
			ans = mid;
		}else r = mid-1;
	}
	cout << a[ans];
	return 0;
}
