#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=29;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(!c[j]&&(a[j]&(1<<i)))sum++;
		}
		if(sum==m){
			int ans=1073741823;
			for(int j=1;j<=n;j++){
				if(!c[j]&&(a[j]&(1<<i)))ans&=a[j];
			}
			cout<<ans;
			return 0;
		}else if(sum>=m){
			for(int j=1;j<=n;j++){
				if(!c[j]&&!(a[j]&(1<<i)))c[j]=1;
			}
		}
	}
	int ans=1073741823;
	for(int i=1;i<=n&&m;i++){
		if(!c[i])ans&=a[i],m--;
	}
	cout<<ans; 
	return 0;
}


