#include <bits/stdc++.h>
using namespace std;
long long ans,l =1,r,n,x,s[200005],s1[200005],sum;
char y;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	cin >> n;
	for(int i =1;i<=n;i++){
		
		cin >> x >> y;
	
		s[sum +1] += y;
		s[sum +x +2] -= y;
		sum+=x;
		
	}
	for(long long i =1;i<=sum;i++){
		s1[i] =s1[i-1]+s[i];
	}
	r = sum;
	while(l<=r){
		if(s1[l]!=s1[r]){
			ans++;
		
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;

}
