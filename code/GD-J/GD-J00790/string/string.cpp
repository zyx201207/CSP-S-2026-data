#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+5;
int n,b[N],cn;
char c[N],new_c[N];
vector<int> a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>b[i]>>new_c[i];
	int cnt=0;
	char val=new_c[1];
	a.push_back(0);
	for(int i=1;i<=n+1;i++){
		if(val!=new_c[i]){
			a.push_back(cnt);
			cn++;
			c[cn]=val;
			val=new_c[i];
			cnt=0; 
		}
		cnt+=b[i];
	}
	if(cn==2){
		if(c[1]==c[2]) cout<<0;
		else cout<<min(a[1],a[2]);
		return 0;
	}
	int l=1,r=cn,f=0,ans=0;
	while(l<=r){
		if(n%2==1&&l+1==r-1) f=1;
		else if(n%2==0&&l==r+1) f=1;
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				if(!f) a[l+1]+=a[l]-a[r];
				else ans+=a[l]-a[r];
			}
			else if(a[l]<a[r]){
				if(!f) a[r-1]+=a[r]-a[l]; 
				else ans+=a[r]-a[l];
			}
		}
		else{ 
			if(a[l]==a[r])
				ans+=a[l];
			else if(a[l]>a[r]){
				ans+=a[r];
				if(!f) a[l+1]+=a[l]-a[r];
				else ans+=a[l]-a[r];
			}
			else{
				ans+=a[l];
				if(!f) a[r-1]+=a[r]-a[l];
				else ans+=a[r]-a[l];
			} 
		}
		l++,r--;
	}
	if(cn%2==0&&c[cn/2]!=c[cn/2+1]) ans+=max(a[cn/2],a[cn/2+1]);
	cout<<ans;
	return 0;
}

