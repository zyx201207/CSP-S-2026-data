#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
using namespace std;
int n,m,ans;
vector<int>a;
signed main(){
	fre("crystal");
	cin>>n>>m;
	a.resize(n);
	for(int&i:a)cin>>i;
	sort(a.begin(),a.end());
	auto i=a.begin(),j=i+1;
	int sum=a[0];
	while(j<a.end()&&i<a.end()){
//		if(i>j)return -1;
		if(sum>=*j*(j-i)-m){
			ans=max(ans,j-i+1);
			sum+=*j;
			j++;
		}
		else{
			sum-=*i;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

