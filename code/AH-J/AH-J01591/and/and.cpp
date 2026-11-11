#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,mans=-2e9;
int a[N],t[5];
void dfs(int xg,int w,int jg){
	if(xg==m){
		mans=max(mans,jg);
		return;
	}
	for(int i=w+1;i<=n;i++){
		dfs(xg+1,i,jg&a[i]);
	}
}
bool cmp(int a,int b){
	return __builtin_popcountll(a)>__builtin_popcountll(b);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool xys=true,ta=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4) xys=false;
		if(__builtin_popcountll(a[i]+1)!=1) ta=false;
	}
	if(n<=20){
		int ans=0;
		mans=-2e9;
		for(int i=1;i<=n;i++){
			dfs(1,i,a[i]);
			ans=max(ans,mans);
		}
		cout<<ans<<endl;
	}
	else if(m==1){
		int ans=-2e9;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
	}
	else if(m==2){
		int ans=-2e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	else if(ta){
		sort(a+1,a+n+1,greater<>());
		cout<<a[m]<<endl;
	}
	else if(xys){
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[4]==0){
			if(t[3]==0){
				if(t[2]==0){
					if(t[1]==0){
						cout<<0<<endl;
					}
					else{
						cout<<1<<endl; 
					}
				}
				else{
					if(t[2]>=m){
						cout<<2<<endl;
					}
					else{
						cout<<0<<endl;
					}
				}
			}
			else{
				if(t[3]>=m){
					cout<<3<<endl;
				}
				else if((t[3]+t[2])>=m){
					cout<<2<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
		}
		else{
			if(t[4]>=m){
				cout<<4<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
	else{
		int ans;
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
