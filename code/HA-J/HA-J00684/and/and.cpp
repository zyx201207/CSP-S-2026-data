#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans=INT_MIN;
bool t=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);  
		if(a[i]>=4){
			t=0;
		}
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}else if(m==n){
		for(int i=1;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){
		for(int i=2;i<=n;i++){
			a[2]&=a[i];
		}
		cout<<a[2];
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
	}
	else{
		for(int i=n;i>=n-m;i--){
			a[n]&=a[i];
		}
		cout<<a[n];
	}
	return 0;
}

