#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n,maxa=-1,cnt,nd;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,(a[i] & a[j]));
			}
		}
		cout<<maxa;
		return 0;
	}
	return 0;
}
