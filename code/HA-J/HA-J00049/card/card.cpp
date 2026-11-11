#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int cn=n;
	int tong[m+5]={0};
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		int tt[m+5]={0};
		for(int i=cn-n;i<=cn;i++){
			if(tt[a[i]]>=1){
				for(int j=i-1;;j--){
					if(a[j]==a[i]){
						break;
					}else{
						tt[a[j]]--;
					}
				}
			}else{
				tt[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(tt[i]){
				tong[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
}
