#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxx1,maxx2;
int a[2200000];
bool v[2200000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx1=max(maxx1,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==maxx1){
			continue;
		}
		else{
			maxx2=max(maxx2,a[i]);
		}
	}
	ans=maxx1&maxx2;
	v[1]=1;
	v[2]=1;
	if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(m==2){
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+1+n,cmp);
		for(int i=3;i<=m;i++){
		int minn=INT_MAX;
		int minw;
		for(int j=3;j<=n;j++){
			if(v[j]==1){
				continue;
			}
			if(minn>abs(ans-a[j])){
     			minn=abs(ans-a[j]);
				minw=j;
			}
	    }
	    ans=ans&a[minw];
	    v[minw]=1;
	}
	cout<<ans;
	}
	return 0;
}
