#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i],ans=max(ans,a[i]);
	if(m==1){
		cout << ans;
	}else if(m==n){
		for(int i=2;i<=n;i++) a[i]=a[i]&a[i-1];
		cout << a[n];
	}else if(ans<4){
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3) x++;
			if(a[i]==2) y++;
			if(a[i]==1) z++;
		}
		if(x>=m) cout << 3;
		else if(x+y>=m) cout << 2;
		else cout << 1;
	}else if(m==2){
		ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout << ans;
	}else if(m==3&&n<=20){
		ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					ans=max(ans,a[i]&a[j]&a[k]);
		cout << ans;
	}else if(m==4&&n<=20){
		ans=0;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int l=k+1;l<=n;l++)
						ans=max(ans,a[i]&a[j]&a[k]&a[l]);
		cout << ans;
	}else if(m==5&&n<=20){
		ans=0;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int l=k+1;l<=n-1;l++)
						for(int p=l+1;p<=n;p++)
							ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[p]);
		cout << ans;
	}else{
		ans=INT_MAX;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++) ans=ans&a[i];
		cout << ans;
	}
	return 0;
} 
