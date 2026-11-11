#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,M,cnt[300010],c[500010],ap[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>c[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			ap[j]=0;
		}
		for(int j=i;j<=N;j++){
			if(ap[c[j]]==1){
				int k=j-1;
				while(k>0&&c[k]!=c[j]){
					ap[c[k]]=0;
					k--;
				}
			}
			else{
				ap[c[j]]++;
			}
		}
		for(int j=1;j<=M;j++){
			cnt[j]+=ap[j];
		}
	}
	for(int i=1;i<=M;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
