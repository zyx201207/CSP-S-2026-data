#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,cnt=0,a[200005],l=1,r;
	cin>>t;
	r=t;
	char b[200005];
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=t;i++){
		if(b[l]!=b[r]){
			//cout<<a[l]<<" "<<a[r]<<endl;
			cnt+=min(a[l],a[r]);
		}
		a[l]-=min(a[l],a[r]);
		a[r]-=min(a[l],a[r]);
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<cnt;
	return 0;
}
