#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		int ans=min(a[0],a[1]);
		if(c[0]==c[1]){
			cout<<0;
		}else{
			cout<<ans;
		}
	}
	return 0;
}
