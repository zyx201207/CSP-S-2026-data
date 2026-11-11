#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool test=true;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) num=a[2]-a[1];
		if(a[i]-a[i-1]!=num&&i>2) test=false;
	}
	if(test){
		if(num==0) cout<<n<<endl;
		else {
			int ans=1;
			for(int i=1;i*num<=m&&ans<n;i++){
				ans++;
			}
			cout<<ans<<endl;
		}
	}else{
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			a[i]-=a[i-1];
		}
		for(int i=1;i<=n;i++){
			s[i]=s[i]+a[i-1];
		}
		a[1]=0;
		int l=1,r=1,num=0;
		int ans=0;
		while(r<=n){
			if(num<=m){
				ans=max(r-l+1,ans);
				r++;
				num+=(s[r]-s[l-1])*(r-l+1);
			}else{
				num-=a[l-1];
				num-=(s[r]-s[l-1]);
				l++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
