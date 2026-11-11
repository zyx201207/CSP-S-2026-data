#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N];
bool ok=1;
void sc(int num,int lst,int sum){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}
	if(lst==n) return ;
	for(int i=lst+1;i<=n;i++){
		sc(num+1,i,(num==0?a[i]:sum&a[i]));
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans<<endl;
		return 0;
	}
	sc(0,0,0);
	cout<<ans<<endl;
	return 0;
}
