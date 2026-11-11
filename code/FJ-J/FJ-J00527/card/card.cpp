#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],last[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],last[a[i]]=i;
	for(int i=1;i<=n;i++){
		int k=i;
		while(k<=n){
			s[a[k]]++;
			k=last[a[k]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
