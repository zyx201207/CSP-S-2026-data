#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n;
int m;
int ans=1;
int a[maxn];
int add[maxn];
vector<int> anss;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		add[i]+=add[i-1];
		anss.push_back(i);
	}
	int z=a[1];
	int t=1,stt=1;
	for(int i=2;i<=n;i++){
		while(a[i]*t-z>m){
			z-=a[stt];
			t--;
			stt++;
		}
		ans=max(ans,t+1);
		z+=a[i];
		t++;
	}
	cout<<ans;
	return 0; 
}  
