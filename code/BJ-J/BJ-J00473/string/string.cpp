#include<bits/stdc++.h>
using namespace std;
int n,a,c,ans;
short st[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(;a>0;a--){
			st[l]=c;
			l++;
		}
	}
	int i=l/2+1,ans=0;
	for(;i<l;i++){
		if(st[i]!=st[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
