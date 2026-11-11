#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];

void sloveAB(){
	int ans = 0;
	for(int i=n;i>=1;i--){
		if(a[n] - a[i] <= m){
			m -= a[n] - a[i];
			ans ++;
		}
		else break;
	}
	
	cout<<ans;
}

void slove(){
	sort(a+1,a+n+1);
	
	int ans = -1;
	for(int i=1;i<=n;i++){
		long long left_m = m;
		int tmp = 1;
		for(int j=i-1;j>=1;j--){
			if(a[i] - a[j] <= left_m){
				left_m -= a[i] - a[j];
				tmp ++;
			}
			else break;
		}
		
		ans = max(ans,tmp);
	}
	
	cout<<ans;
}

int main(){
	
//	double st = clock();
	
//	freopen("crystal3.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	bool flagA = true;
	bool flagB = true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != i) flagA = false;
		if(i >= 3){
			if(a[i] - a[i-1] != a[i-1] - a[i-2]) flagB = false;
		}
	}
	
	if(flagA || flagB){
		//Ãÿ ‚–‘÷  A/B
//		cerr<<(flagA?"A":"B")<<"\n";
		sloveAB();
	}
	else{
//		cerr<<"common\n";
		slove();
	}
	
	
//	double et = clock();
//	cerr<<"\n"<<et-st<<"ms";
	
	return 0;
} 
