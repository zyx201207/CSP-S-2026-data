#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ma,anss,a[200005],maa;
bool p[200005][20],ans[200005];
int cnt[30];
signed main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=a[i];
		if(a[i]==0){
			continue;
		}
		while(1){
			int x=1,j=1;
			while(1){
				j++;
				x=x*2;
				if(x>b){
					j--;
					x=x/2;
					ma=max(ma,j);
					p[i][j]=1;
					break;
				}
			}
			b=b-x;
			if(b==0){
				break;
			}
		}
		maa=max(maa,a[i]);
	}
	if(m==1){
		cout<<maa;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=ma;j++){
			if(p[i][j]==1){
				cnt[j]++;
			}
		}
	}
	int cc=0;
	for(int k=0;k<=ma;k++){
		for(int i=1;i<=n;i++){
			for(int j=ma;j>=k;j--){
				if(p[i][j]==0&&cnt[j]>=m){
					break;
				}
				if(j==k&&ans[i]!=1){
					ans[i]=1;
					cc++;
				}
			}
		}
		if(cc>=m){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==1){
			if(anss==0){
				anss=a[i];
			}
			else{
				anss=anss&a[i];
			}
		}
	} 
	cout<<anss;
	return 0;
}
