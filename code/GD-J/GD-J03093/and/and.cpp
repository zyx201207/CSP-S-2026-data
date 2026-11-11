#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
int n,m,ans;
int a[M];
bool A=1,B=1,mx4=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n&(n-1)!=0)B=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&(a[i]+1)!=0)A=0;
		if(a[i]!=i-1)B=0;
		if(a[i]>=4)mx4=0;
	}
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int cnt=0,anse=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					cnt++;
					if(!anse)anse=a[j+1];
					else anse&=a[j+1];
				}
			}
			if(cnt==m)ans=max(ans,anse);
		}
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}else if(A){
		sort(a+1,a+1+n,[](int x,int y){
			return x>y;
		});
		ans=a[1];
		for(int i=2;i<=m;i++)ans&=a[i];
		cout<<ans;
	}else if(B){
		for(int i=n;i>=1;i--){
			if(!(m--))break;
			if(a[i]&(a[i]-1)==0)continue;
			if(!ans)ans=a[i];
			ans&=a[i];
		}
		
		cout<<ans;
	}else if(mx4){
		set<int>st;
		vector<int>v;
		for(int i=1;i<=n;i++)st.insert(a[i]);
		for(auto x:st){
			v.push_back(x);
		}
		sort(v.begin(),v.end(),[](int x,int y){
			return x>y;
		});
		for(int i=1;i<=m;i++){
			if(!ans)ans=a[i];
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
