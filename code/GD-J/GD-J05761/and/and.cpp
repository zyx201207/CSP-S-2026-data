#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,ma=0,ans=0,cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=a[n];
	a[n]=0;
	for(int j=1;j<m;j++){
		int ans=0;
		int ma=0;
		for(int i=1;i<=n;i++){
			if(cnt&a[i]>ma){
				ma=cnt&a[i];
				ans=i;
			}
		}
		cnt&=a[ans];
		a[ans]=0;
		sort(a+1,a+n+1);
	}
	cout<<cnt;
}
