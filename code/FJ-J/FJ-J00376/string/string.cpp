#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int a[N];
char b[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	string s="";
	int maxx=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==1){
		cout<<0;
		return 0;	
	}else if(n==2){
		if(a[1]==a[2]||b[1]==b[2]){
			cout<<0;
			return 0;
		}else{
			int minn=min(a[1],a[2]);
			cout<<minn;
			return 0;
		} 
	}else if(maxx==1){
		cout<<n/2;
	}else{
		cout<<ans/2;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
