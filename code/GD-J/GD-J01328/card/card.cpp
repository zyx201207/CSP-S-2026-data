#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],lst[N],ans[N],st[N][22];
void sol1(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=lst[a[j]]+1){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)cout<<" ";
	}
}
void sol2(){
	for(int i=1;i<=n;i++)ans[a[i]]++;
	for(int i=1;i<=m;i++){
		ans[i]+=ans[i-1];
		cout<<ans[i];
		if(i<m)cout<<" ";
	}
}
pair<int,int> q[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flg=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		if(a[i]<a[i-1])flg=0;
	}
	if(n<=5000||m<=2)sol1();
	else if(flg)sol2();
	return 0;
}
