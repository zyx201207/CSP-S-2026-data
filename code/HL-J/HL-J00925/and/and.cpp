#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int t2(int s){
	int ans=0;
	while(s!=0){
		if(s%2==1) ans+=1;
		else ans+=0;
		s/=2;
	}
	return ans;
}
bool cmp(int a,int b){
	if(t2(a)>t2(b)) return true;
	else if(t2(a)==t2(b)){
		if(a>b) return true;
		else return false;
	}
	else return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
}