#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		int x=0,y=1;
		for(int j=i-1;j>=0;j--){
			x+=a[i]-a[j];
			y++;
			if(x>m){
				y-=1;
				break;
			}else if(x==m){
				break;
			}
		}
		cnt=max(cnt,y);
	}
	cout<<cnt;
	return 0;
} 
