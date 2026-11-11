#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}
int s[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	cout<<s[m];
	
	return 0;
}
