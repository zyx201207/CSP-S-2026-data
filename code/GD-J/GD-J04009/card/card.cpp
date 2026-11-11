#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,s[N],last[N],z[N],k[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			z[j]=s[j];
			if(last[z[j]]==0){
				last[z[j]]=j;
			}
			else{;
				for(int p=last[s[j]];p<j;p++){
					last[z[p]]=0;
					z[p]=0;
				}
				last[z[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(z[j]>0){
				k[z[j]]++;
				last[z[j]]=0;
				z[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
