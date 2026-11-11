#include<bits/stdc++.h>
using namespace std;
int a[20005],ad[20005],tp[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ad[i]=a[i];
	}
	while(m>0){
		for(int i=1;i<=n;i++){
			tp[i]=ad[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ad[i]&=tp[j];
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,ad[i]);
	}
	cout<<mx;
	return 0;
}
