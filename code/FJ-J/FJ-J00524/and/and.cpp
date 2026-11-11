#include<bits/stdc++.h>
using namespace std;

int n,m;
int maxx=-114514;
int a[5000005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	
	/*for(int i=0;i<n;i++){
		cout<<a[i];
	}*/

	return 0;
}

