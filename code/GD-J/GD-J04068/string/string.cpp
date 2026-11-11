#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
int n,num[N];
ll ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>num[i]>>s[i];
	int l=1,r=n;
	while(l<=r){
		if(s[l]!=s[r])	ans+=min(num[l],num[r]);
		if(num[l]>num[r]){
			num[l]-=num[r];
			r--;
		}
		else if(num[l]<num[r]){
			num[r]-=num[l];
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
