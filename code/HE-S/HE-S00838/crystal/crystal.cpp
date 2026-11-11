#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,ans[500005],anss,amax=-1*1e+9;
void aa(int x,int xx){
	if(x>m){
		return;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
	}
	for(int i=1;i<=amax;i++){
		anss=max(ans[i],anss);
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		a[i]+=1;
		x++;
		aa(x,xx+1);
		a[i]--;
		x--;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amax=max(amax,a[i]);
	}
	aa(0,1);
	cout<<anss;
	return 0;
}
