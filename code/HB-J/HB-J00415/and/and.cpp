#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005];
bool fps[10009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n-m;i++){
		int jg=a[i];
		for(int j=1;j<=m;j++){
			jg &= a[i+j];
			if(jg<ans){
				break;
			}
		}ans=max(jg,ans);
	}
	cout << ans;
	return 0;
}
