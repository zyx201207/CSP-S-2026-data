#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],cnt[100005],ble[1000005],top=0;
void Go(int x){
	ble[++top]=x;
	for(int i=1;i<top;i++){
		if(ble[i]==x){
			top=i;
			return;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=1;
	for(int i=1;i<=n;i++) if(a[i]<a[i-1]){flag=0;break;}
	if(flag){
		long long all_card=0;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			all_card+=cnt[i];
			cout<<all_card<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			Go(a[j]);
		}
		for(int i=1;i<=top;i++){
			cnt[ble[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
