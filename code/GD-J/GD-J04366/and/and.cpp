#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,m,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int w=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		w=max(w,a[i]);
	}
	if(m==1){
		cout<<w;
		return 0;
	}if(m==n){
		int ans=0;
		for(int i=0;i<n;i++){
			if(i==0){
				ans=a[0];
			}
			else {
				ans=ans&a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		int ans=-1;
		for(int j=0;j<(1<<n);j++){
			int s=0,cnt=0,flag=0;
			for(int i=0;i<n;i++){
				if(j&(1<<i)){
					if(flag==0){
						cnt=a[i];
						flag=1;
						s++;
						continue;
					}
					cnt=cnt&a[i];
					s++;
				}
			}
			if(s==m){
				ans=max(ans,cnt);
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
