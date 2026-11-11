#include <bits/stdc++.h>
using namespace std;
int mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >>m;
	int nn[n+5];
	for(int i=1;i<=n;i++){
		cin >> nn[i];
	}
	for(int i=1;i<=n;i++)
	{
		int h[m+5];
		int t[n+5];
		for(int j=1;j<=n;j++){
			h[j]=0;
			t[j]=0;
		}
		for(int j=i;j <= n;j++){
			h[nn[j]]++;
			if(h[nn[j]]==2){
				int p=j-1;
				while(h[nn[j]]==2){
					if(t[nn[p]==0]){
						h[nn[p]]--;
						t[nn[p]]=1;
					}
					p--;
				}
			}
			for(int i=1;i<=n;i++){
				mm[i]+=h[i];
			}
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<mm[i]<<" ";
	}
	return 0;
}