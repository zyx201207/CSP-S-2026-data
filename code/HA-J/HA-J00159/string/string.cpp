#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<long long> a;
	while(n--){
		int q;
		char c;
		cin>>q>>c;
		for(int i=0;i<q;i++){
			a.push_back(c);
		}
	}
	int l=0,r=a.size()-1;
	int ans=0;
	while(l<r){
		if(a[l]==a[r]){
			l++;
			r--;
		}
		else if(a[l]!=a[r]){
			ans++;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
