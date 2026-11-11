#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int a[1000006];
char b[1000006];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	int l=1,r=n;
	int cnt=0;
	while(num!=0&&l<=r){
		if(num==1)break;
		if(b[l]!=b[r]){
			cnt+=min(a[l],a[r]);
			num-=2*min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
		else{
			a[r]-=a[l];
			r++;
		}
	}
	cout<<cnt;
	return 0;
} 
