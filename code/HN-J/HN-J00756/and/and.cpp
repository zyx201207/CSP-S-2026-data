#include<bits/stdc++.h> 
using namespace std; 
int n,m;
int a[200005],b[200005];
int minn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			minn=max(minn,a[i]);
		}
		cout<<minn;
		return 0;
	}
	return 0;
}
