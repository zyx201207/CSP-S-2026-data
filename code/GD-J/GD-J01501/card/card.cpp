#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[300005];
bool hc[300005];
long long game[500005];
int main(){
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
 
	for(long long i = 1;i<=n;i++){
		for(int i = 1;i<=m;i++){
			hc[i] = false;
		}
		memset(game,0,n); 

		long long ist = 0;
		for(long long j = i;j<=n;j++){
			if(!hc[a[j]]){
				
				ist++;
				game[ist] = a[j];
				hc[a[j]] = true;

			}
			else{
				while(game[ist] != a[j]){
					hc[game[ist]] = false;
					ist-=1;				
				}
				hc[a[j]] = true;
			}
		}
		
		for(long long j = 1;j<=ist;j++){
			ans[game[j]] +=1;
		}
		
	}
	
	for(long long i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
