#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ANS;
int a[500010],ans[500010];
/*
inline int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return s*f;
}
inline void write(int x){
	string S="";
	while(x){
		S+=x%10-'0';
		x/=10;
	}
	for(int i=S.size()-1;i>=0;i--) cout<<S[i];
}
*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,c=0;
	for(int r=1;r<=n;r++){
		if(r==1){
			ans[r]=1;
		}
		else if(a[r]!=a[r-1]){
			c+=(r-l)*(a[r]-a[r-1]);
//			cout<<l<<" "<<r<<" "<<c<<"\n";
			while(c>m&&l<r){
				c-=a[r]-a[l];
				l++;
//				cout<<l<<" "<<r<<" "<<c<<"\n";
			}
			ans[r]=r-l+1;
		}
		else{
			ans[r]=ans[r-1]+1;
		}
		ANS=max(ANS,ans[r]);
	}
	cout<<ANS;
	return 0;
}

