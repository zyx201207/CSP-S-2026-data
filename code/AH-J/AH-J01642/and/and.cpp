#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
		cout<<cnt;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
	}
	return 0;
}
