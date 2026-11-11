#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],ans;
char c[200005];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		int t=max(x[i],x[n-i+1]);
		while(t>0){
			if(c[i]!=c[n-i+1]){
				ans+=min(x[i],x[n-i+1]);
				t-=min(x[i],x[n-i+1]);
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
