#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200010];
	int flag[200010];
	int ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(anx==0){
			int index=a[i]
			bool flag=false;
			while(index>1){
				if(index%!=0){
					flag=true;
					break;
				}
				index/=2;
			}
			if(flag==true){
				ans=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
