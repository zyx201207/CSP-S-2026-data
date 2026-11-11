#include<bits/stdc++.h>
using namespace std;
int n,a[200010],a_[200010],ans;
string s,c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	a_[i]=a_[i-1]+a[i];
	}
	int ti=1,tj=n;
	for(int i=0,j=a_[n]-1;i<j;i++,j--){
		if(i>=a_[ti])ti++;
		if(j<a_[tj-1])tj--;
		ans+=(c[ti]!=c[tj]);
	}
	cout<<ans;
	return 0;
}
