#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int q,w;
	cin>>q>>w;
	int ans=0;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	if(q==w){
		for(int i=1;i<=q;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=q;i++){
		for(int j=i;j<=q;j++){
			ans=max((a[i]&a[j]),ans);
		}
	}
	cout<<ans;
	return 0;
}
