#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int add(int s,int x){
	int ans;
	if(x==m)return s;
	for(int i=1;i<=n;i++){
		if(x==0)ans=max(s,add(a[i],1));
		else ans=max(s,add(a[i]&x,x+1));
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<add(0,0); 
	return 0;
}

