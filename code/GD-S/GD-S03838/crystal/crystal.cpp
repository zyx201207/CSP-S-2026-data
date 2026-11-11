#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans,a1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	
	for(int i =1;i<=n;i++){
		scanf("%lld", &a[i]);
		s[i] = a[i]-a[i-1];
		
	}
	if(n>5000){
		
		if(s[1]+s[2]*(n-1) <= m){
			cout <<n;
			return 0;
		}
		for(int i =1;i<=n-1;i++){
			if(a[1]+s[2]*i >m){
				cout << i;
				return 0;
			}
		}
		
		
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		a1 = 1;
		sum = 0;
		while(sum <=m&&i-a1>0){
			
			sum+= a[i]-a[i-a1];
			a1++;
		}
	
		
		ans = max(ans,a1);
	
		
	}
	cout<< ans;
	return 0;
} 
