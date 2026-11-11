#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[2000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	long long ans=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int a=1;a<=n;a++){
		cin>>num[a];
	}
	sort(num+1,num+n+1,cmp);
	ans=num[1];
	for(int a=2;a<=m;a++){
		ans&=num[a];
	}
	cout<<ans;
	return 0;
}
