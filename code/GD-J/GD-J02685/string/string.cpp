#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum,a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m+=a[i];
		char q;
		cin>>q;
		for(int j=1;j<=a[i];j++) s+=q;
	}
	for(int l=0,r=m-1;l<=r;l++,r--){
		if(s[l]!=s[r]) sum++;
	}
	cout<<sum;
	return 0;
}
