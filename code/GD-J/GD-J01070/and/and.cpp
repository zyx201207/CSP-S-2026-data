#include<bits/stdc++.h>
using namespace std;


int a[200005],n,m,ans;

int qwq(int pos,int wz,int sum){
	if(pos>m){
		ans=max(ans,sum);
		return 0;
	}
	for(int i=wz+1;i<=n;i++){
		if(sum<0){
		                          
			qwq(pos+1,i,a[i]);
		}
		else{
	                               
			qwq(pos+1,i,a[i]&sum);
		}
	}
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qwq(1,0,-1);
	cout<<ans;
	return 0;
}

