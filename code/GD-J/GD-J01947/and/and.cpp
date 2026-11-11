#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[200005];
int ans = 0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		if(i>n-m)break;
		int cnt=1;
		int sum=a[i];
		for(int j = i+1;j<=n;j++){
			if(cnt==m||cnt+n-j<m)break;
			bool f = (a[i]&a[j])==a[j];
			if(f){
				sum=a[j];
				cnt++;
			}
		}
		if(cnt==m)ans=max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}
