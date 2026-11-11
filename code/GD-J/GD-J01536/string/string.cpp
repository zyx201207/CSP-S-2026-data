#include<bits/stdc++.h>
using namespace std;
const int Q=1e5*2+5;
int n,cnt;long long ans;
string s[Q];
int x[Q];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		
	}
	int left=1;int right=n;
	while(left<=right){
		cnt=min(x[left],x[right]);
		x[left]-=cnt;x[right]-=cnt;
		if(s[left]!=s[right]){
			ans+=cnt;
		}
		if(x[left]==0) left++;
		if(x[right]==0) right--;
	}
	cout<<ans;
	return 0;
}

