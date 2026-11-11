#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
struct S{
	int sl;
	char dc;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].dc;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].sl>=a[r].sl){
			if(a[l].dc!=a[r].dc)
			ans+=a[r].sl;
			a[l].sl-=a[r].sl;
			r--;
			if(a[l].sl==0)
			l++;
		}else{
			if(a[l].dc!=a[r].dc)
			ans+=a[l].sl;
			a[r].sl-=a[l].sl;
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
