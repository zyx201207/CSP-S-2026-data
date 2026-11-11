#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long a[N];
long long b[505];
long long n,m;
bool ck3=1,ck1=1,ck2=1;

bool check(int x){
	for(int i=x; i<=n; i++){
		long long sum=0;
		bool ck=1;
		for(int j=i-x+1; j<=i-1; j++){
			
		}
		if(ck) return 1;
	}
	return 0;
}

bool check2(int x){
	for(int i=x; i<=n; i+=b[a[i]]){
		long long sum=0;
		bool ck=1;
		for(int j=i-x+1; j<=i-1; j++){
			sum+=(a[i]-a[j]);
			if(sum>m){
				ck=0; break;
			}
		}
		if(ck) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=i) ck3=0;
		if(i==1) continue;
		if(a[i]-a[i-1]!=a[2]-a[1]) ck1=0;
		if(!ck2) continue;
		if(a[i]<=505){
			b[a[i]]++;
			ck2=1;
		}
		else ck2=0;
	}
	
	sort(a+1,a+n+1);
	if(ck3){
		long long sum=0;
		for(int i=2; i<=n; i++){
			sum+=i-a[1];
			if(sum>m){
				cout<<i-1<<'\n';
				return 0;
			}
		}
	}
	
	if(ck1){
		long long sum=0;
		for(int i=2; i<=n; i++){
			sum+=a[i]-a[1];
			if(sum>m){
				cout<<i-1<<'\n';
				return 0;
			}
		}
	}
	
	if(ck2){
		int l=0,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check2(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
/*5 5
1 2 4 8 9*/
