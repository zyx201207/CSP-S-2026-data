#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,r,l,end,ans;
string a = "";
string c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(i = 0;i<n;i++){
		k = 0;
		c = "";
		cin>>k>>c;
		end =end+ k;
		while(k--){
			a =a+c;
			
		}
	}
	l = 0;
	r = end-1;
	while(r>l){
		if(a[l]!=a[r]){
			a[r] = a[l];
			ans++;
			l++;
			r--;
		}else{
			l++;
			r--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
