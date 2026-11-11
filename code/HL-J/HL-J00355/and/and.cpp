#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int s[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a;int b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	sort(s+1,s+a+1,cmp);
	int tmp=s[1];
	for(int i=2;i<=b;i++){
		tmp=tmp&s[i];
	}
	cout<<tmp;
	return 0;
}
