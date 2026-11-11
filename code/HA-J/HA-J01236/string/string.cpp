#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long ans=0,sum,w,y;
	int n,a[200005];
	string s[200005],q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++){
			q=q+s[i];
		}
	}
	sum=q.size();
	w=(sum-1)/2;
	y=(sum/2-1);
	if(sum%2==0){
		for(long long i=0;i<=w;i++){
			if(q[i]!=q[sum-1-i]){
				ans+=1;
			}
		}
	}else{
		for(long long i=0;i<=y;i++){
			if(q[i]!=q[sum-1-i]){
				ans+=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
