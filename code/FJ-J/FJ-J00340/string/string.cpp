#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long cnt[200005];
string ans[200005];
int len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2){
		long long minn=10;
		for(int i=1;i<=n;i++){
			cin>>cnt[i]>>ans[i];
			minn=min(minn,cnt[i]);
		}
		int h=1;
		for(int i=2;i<=n;i++){
			if(ans[i]==ans[i-1]){
				h++;
			}
		}
		if(h==n){
			cout<<0;
			return 0;
		}
		cout<<minn;
		return 0;
	}
	long long num=0,maxn=0;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>ans[i];
		if(ans[i]==ans[i-1]){
			if(m>maxn){
				maxn+=cnt[i];
			}
			m+=cnt[i];
//			cout<<maxn<<endl;
		}
		else{
			m=0;
		}
		maxn=max(maxn,cnt[i]);
		num+=cnt[i];
	}
	int h=1;
	for(int i=2;i<=n;i++){
		if(ans[i]==ans[i-1]){
			h++;
		}
	}
	if(h==n){
		cout<<0;
		return 0;
	}
//	cout<<num<<" "<<maxn<<endl;
	if(num-maxn<=maxn){
		cout<<num-maxn;
		return 0;
	}
//	else{
//		
//	}
//	cout<<n;
	return 0;
}
