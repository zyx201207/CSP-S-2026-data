#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e6+1;
long long poker[N],cnt[N];
long long table[1001][1001];
int biao[1001][1001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>poker[i];
	}
	for(int i=1;i<=n;i++){
		long long tmp=1;
		for(int j=i;j<=n;j++){
			table[i][tmp]=poker[j];
			biao[i][table[i][tmp]]++;
			long long tmpt=table[i][tmp];
			if(biao[i][table[i][tmp]]>=2){
				table[i][tmp]=0;
				while(table[i][tmp]!=tmpt){
					biao[i][table[i][tmp]]--;
					table[i][tmp]=0;
					tmp--;
				}
			}
			tmp++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cnt[table[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
