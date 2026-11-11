#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,f;
struct AA{
	int x;
	char y;
};
AA a[200100];
int b[1000100],c[1000100];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(i>=2&&a[i].y==a[i-1].y) f++;
		for(int j=1;j<=a[i].x;j++) s+=a[i].y;
	}
	if(f==n-1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		b[i+1]=(int)(s[i]-'a');
	}
	for(int i=1;i<=s.size()/2;i++){
		if(b[i]!=b[s.size()-i+1]) sum++;
	}
	cout<<sum;
	return 0;
}
