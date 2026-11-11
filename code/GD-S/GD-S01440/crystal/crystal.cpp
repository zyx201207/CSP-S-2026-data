#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int s[N],a[N],d[N];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
unordered_map<int,int> mp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
//	for(int i=1;i<n;i++) s[i]=s[i-1]+(a[i]-a[i-1]);
//	for(int i=1;i<n;i++) d[i]=d[i-1]+s[i]=;
	if(n<=5000){
		sort(a+1,a+1+n);
		int ans=-1;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=i+1;j<=n;j++){
				if(cnt+(a[j]-a[j-1])*(j-i)<=m){
					ans=max(ans,j-i+1);
					cnt+=(a[j]-a[j-1])*(j-i);
					//cout<<"j"<<j<<" "<<"i"<<i<<" "<<"cnt"<<cnt<<endl;
				}else break;
			}
		}
		cout<<ans<<endl;
	}else{
		if(a[2]-a[1]==0){
			cout<<n<<endl;
			return 0;
		}
		if(abs(a[2]-a[1])==abs(a[3]-a[2])){
			for(int i=n;i>=1;i++) 
				if(abs(a[2]-a[1])*i*(i-1)/2<=m){
					cout<<i+1<<endl;
					break;
				}
			return 0;
		}else{
			int ans=-1;
			for(int i=1;i<=n;i++) mp[a[i]]++;
			for(auto i:mp) ans=max(ans,i.second); 
		}
		
	}
		
	
	 
	return 0;
}
/*
5 5
1 2 4 8 9


*/
