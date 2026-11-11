#include<bits/stdc++.h>
using namespace std;
int n,a[1010100],b[500010],m;
vector <int>ve[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int x=1;x<=m;x++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int f=1,cnt;
			for(int i=j;i<=n;i++){
				if(i==a[x]){
					cnt++;
				}
			}
			ans+=1;
		}
		cout<<ans<<' ';
	}
	return 0;
} 
