#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
int pre[40],a[N],ans=1,n,m;
bool cmp(int x,int y){
	int a=pre[lower_bound(pre+1,pre+31,x)-pre]-x;
	int b=pre[lower_bound(pre+1,pre+31,y)-pre]-y;
	if(a!=b) return (a==0?a>b:a<b);
	else if(a+x!=b+y) return (a!=0?a+x>b+y:a+x<b+y);	
	else{
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++){
		pre[i]=pow(2,i);
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=2;i<=m;i++){
		ans&=a[i];
//		cout<<a[i]<<" ";
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
