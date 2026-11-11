#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005][35];
int cnt[35];
int _2[35];
int ok[35];
int n,m;
bool check(int x){
	for(int l=0;l<30;l++){
		if(ok[l]==1&&b[x][l]==0){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=30;i++){
		_2[i]=(1<<i);
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=29;j>=0;j--){
			if(a[i]>=_2[j]){
				a[i]-=_2[j];
				b[i][j]=1;
				cnt[j]++;
			}
		}
	}
	for(int k=29;k>=0;k--){
		if(cnt[k]>=m){
			ok[k]=1;
			int cnt2=0;
			for(int i=1;i<=n;i++){
				if(check(i)){
					cnt2++;
				}
			}
			if(cnt2<m){
				ok[k]=0;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=30;i++){
		ans=ans+ok[i]*_2[i];
	}
	cout<<ans;
	return 0;
}

