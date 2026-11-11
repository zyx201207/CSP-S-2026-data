#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005],ma=0,cnt;
bool b[200005][35],us[200005],ans[35];
void chec(int a,int i){
	int h=1;
	while(a>=1){
		b[i][h]=a%2;
		a=a/2;
		h++;
	}
	s[i]=h;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		chec(a[i],i);
		ma=max(ma,s[i]);
	}
	for(int i=ma;i>=1;i--){
		int u=0;
		for(int j=0;j<n;j++){
			if(b[j][i]==1 && us[j]==0){
				u++;
			}
		}
		if(u>=m){
			ans[i]=1;
			for(int j=0;j<n;j++){
				if(b[j][i]!=1){
					us[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=ma;i++){
		if(ans[i]==1){
			int k=1;
			for(int j=1;j<i;j++){
				k=k*2;
			}
			cnt+=k;
		}
	}
	cout<<cnt;
	return 0;
} 
