//GZ-J00173  遵义航天高级中学  刘鑫馨
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin>>n;
	if (n==1) {
		cout<<0;
		return 0;
	}
	string s;
	int sum=0;
	for(int i=1;i<=n;i++){
		int l;
		char c;
		cin>>l>>c;
		sum+=l;
		for(int i=1;i<=l;i++){
			s+=c;
		}
	}
	int ans=0;
	for(int i=1;i<=sum/2+1;i++){
		if(s[i]==s[sum-i+1]){
			continue;
		}else{
			ans++;
		}
	} 
	if(sum%2!=0){
		ans--;
	}
	cout<<ans;
	return 0;
}
