#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans[N];
int a[N];
int far[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>=1;--i){
		if(!far[a[i]]){
			far[a[i]]=i;
		}
	}
	for(int i=1;i<=n;++i){
		int p=i;
		while(p<=n){
			if(far[a[p]]==p){
				ans[a[p]]++;
				p++;
			}
			else{
				ans[a[p]]++;
				p=far[a[p]]+1;
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
