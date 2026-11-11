#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6+5;

int a[N];
int n,m;
int cha=0;
	
bool check(int x){
	int num = (1+x)*x/2;
	if(num<=m) return true;
	else return false;
}

bool check1(int x){
	int num = (a[1]+a[x])*((a[x]-a[1])/cha+1)/2;
	if(num<=m) return true;
	else return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	bool A=1,B=1;
	
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
		if(a[i]!=i) A=0;
	}
	sort(a+1,a+n+1);
	cha = a[2]-a[1];
	for(int i=3;i<=n;i++) {
		if((a[i]-a[i-1])!=cha) B=0; 
	}

	int ans=-114514;
	
	if(A){
		int l=1,r=n;
		while(l+1<r){
			int mid = (l+r)/2;
			if(check(mid)){
				l=mid;
			}
			else {
				r=mid;
			}
		}
		cout<<r;
		return 0;
	}
	
	if(B){
		int l=1,r=n;
		while(l+1<r){
			int mid = (l+r)/2;
			if(check1(mid)){
				l=mid;
			}
			else {
				r=mid;
			}
		}
		cout<<r;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int sum=m,cnt=0;
		vector<int> b;
		for(int j=1;j<=i;j++){
			b.push_back(a[i]-a[j]);
		}
		sort(b.begin(),b.end());
		for(int j=0;j<i;j++){
			sum-=b[j];
			if(sum>=0) cnt++;
		} 
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
