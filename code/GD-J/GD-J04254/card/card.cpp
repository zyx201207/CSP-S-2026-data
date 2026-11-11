#include<bits/stdc++.h>
using namespace std;
long long int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdin);
	cin>>n>>m;
	long long int s[m+1],sum[m+1],cnt = 1,poket[m+1];
	bool flag[m+1];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		flag[i] = false;
		sum[i] = 0;
		poket[i] = 0;
	}
	for(int i =1;i<=n;i++){
		for(int j = cnt;j<=n;j++){
			if(flag[s[j]] == 0){
				flag[s[j]] = 1;
				poket[s[j]] = j;
			}
			else{
				for(int k = 1;k<=m;k++){
					if(poket[k]>=poket[s[j]]){
						flag[k] = 0;
					}
				}
			}
		}
		for(int j = 1;j<=m;j++){
			if(flag[j]){
				sum[j]++;
			}
			flag[j]=0;
			poket[j] = 0;
		}
		cnt++;
	}
	for(int i = 1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
