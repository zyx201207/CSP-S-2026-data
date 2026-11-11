#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<char> v;
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int num;char c;cin>>num>>c;
		for(int j=1;j<=num;j++){
			v.push_back(c);
		}
	}
	int sum=v.size();
	int half=sum%2+1;
	int ans=0;
	if(sum%2==0){
		for(int i=half-1;i<sum;i++){
			if(v[i]!=v[2*half-i-1]){
				v[i]=v[2*half-i-1];
				ans++;
			}
		}
	}else{
		for(int i=half;i<sum;i++){
			if(v[i]!=v[2*half-i]){
				v[i]=v[2*half-i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}