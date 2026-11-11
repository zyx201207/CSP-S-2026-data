#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N =2e5+5;
ll a[N];
ll m,n,ans,o_ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m==2){
		for(int i=0;i<n;++i){
		for(int j=i;j<n;j++){
			ans = a[i] & a[j+1];
			if(ans>=o_ans){
			o_ans = ans;
				} 
			}
		}
	}else if(m==3){
		for(int i=0;i<n;++i){
		for(int j=i;j<n;j++){
			ans = a[i] & a[j+1]&a[j+2];
			if(ans>=o_ans){
			o_ans = ans;
				} 
			}
		}
	}
	
	
	cout << o_ans << endl;
		
	return 0;
} 
