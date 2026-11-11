#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[200005],ans=-1;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>ans)ans=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(k!=2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int an=a[i];
			for(int j=1;j<=k;j++){
				if(i<=k)break;
				an=an&a[i-j];
			}
			if(an>ans)ans=an;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++){
			int an=a[i]&a[j];
			if(an >= ans)ans=an;
		}
	}
	cout<<ans;
	return 0;
} 
