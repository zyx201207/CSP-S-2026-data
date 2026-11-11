#include<bits/stdc++.h>
using namespace std;
int n,m;
int t=0;
int a[2000005];
bool cmp_2(int x,int y){
	if(((x>>t)&1)!=((y>>t)&1)){
		return ((x>>t)&1)>((y>>t)&1);
	}
	else{
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	t=32;
	long long ans=4294967295;
	while(t!=0){
		int flag=0;
		sort(a+1,a+1+n,cmp_2);
		for(int i=1;i<=n;i++){
			if(((a[i]>>t)&1)){
				flag++;
			}
			if(flag==m){
				for(int j=1;j<=m;j++){
					ans=ans&a[j];
				}
				cout<<ans;
				return 0;
			}
		}
		t--;
	}
	cout<<"0";
	return 0;
}
