#include <bits/stdc++.h>
using namespace std;
int num[500010];
int p[500010];
int tt[300010];
int ttt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int t=1;t<=n;t++){
		cin>>num[t];
	}
	int k;
	for(int i=1;i<=n;i++){
		for(int t=1;t<=n;t++){
			p[t]=0;
		}
		for(int t=1;t<=m;t++){
			tt[t]=0;
		}
		k=num[i];
		for(int t=i;t<=n;t++){
			p[t]=num[t];
			if(tt[num[t]]==0){
				tt[num[t]]++;
			}else{
				for(int x=i;x<=n;x++){
					if(num[x]==num[t]){
						k=x;
						tt[x]=1;
						break;
					}
				}
				for(int x=k;x<t;x++){
					p[x]=0;
				}
			}
		}
			for(int q=1;q<=n;q++){
				if(p[q]!=0){
					ttt[p[q]]++;
				}
			}
	}
	for(int t=1;t<=m;t++){
		cout<<ttt[t]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
