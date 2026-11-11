#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
string tobin(int n){
	string bin;
	while(n>0){
		int r=n%2;
		if(r){
			bin+="1";
		}
		else{
			bin+="0";
		}
		n/=2;
	}
	reverse(bin.begin(),bin.end());
	return bin;
}
int tobincmp(int n){
	string m=tobin(n);
	int cmt=0;
	for(int i=0;i<m.size();i++){
		if(m[i]=='1')cmt++;
	}
	return cmt;
}
bool cmp(int a,int b){
	return tobincmp(a)>tobincmp(b);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans;//=a[0];
	if(m==1){
		cout<<a[0];
	}
	else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
	}
	else cout<<a[m];
	//cout<<ans;
	return 0;
}
