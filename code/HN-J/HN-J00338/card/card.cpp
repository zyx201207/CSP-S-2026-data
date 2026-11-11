#include<bits/stdc++.h>
using namespace std;
int n,m,ps,ans;
int a[10005],b[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>a[i];
	for(int i=1;;i++){
		if(ps<=0) break;
		b[i]=a[i];
		if(a[i-1]==a[i]){
			b[i]-=a[i-1];
		}
		ps--;
		ans++;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i];
	cout<<ans;
	return 0;
}
