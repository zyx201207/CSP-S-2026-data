#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int mx=-999;
	int a[10005],n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=2;i<=n;i++){
			mx=max(mx,a[i]&a[i-1]);
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
	}
	else{
		for(int i=2;i<=n;i++){
			num=a[1];
			num=num&a[i];
		}
		mx=num;
	}
	cout<<mx;
	return 0;
}
