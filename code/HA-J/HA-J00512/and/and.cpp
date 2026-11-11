#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maz,ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=0;
	sort(a+1,a+1+n,greater<int>());
	for(int q=1;q<=m;q++){
		maz=ma;	
		ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>ma){
					ma=a[i]&a[j];
				}
			}
		}
		
	}
	cout<<maz;
	return 0;
}
