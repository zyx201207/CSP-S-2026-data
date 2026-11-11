#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool s[200010];
_Ios_Fmtflags ans;
int qu(int x,int y){
	if(x==m) return y;
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(!s[i]){
			s[i]=true;
			maxn=max(maxn,qu(x+1,(_Ios_Fmtflags(static_cast<int>(y) & static_cast<int>(a[i])))));
			s[i]=false;
		}
	}
	return maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(_Ios_Fmtflags(static_cast<int>(a[i]) & static_cast<int>(a[j]))));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=_S_ios_fmtflags_end;
		for(int i=1;i<=n;i++){
			ans&=_Ios_Fmtflags(a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++)
				ans=max(ans,(_Ios_Fmtflags(static_cast<int>(a[i]) & static_cast<int>(a[j])&static_cast<int>(a[k]))));
			}
		}
		cout<<ans;
	}
	cout<<qu(0,pow(2,32));
	return 0;
}

