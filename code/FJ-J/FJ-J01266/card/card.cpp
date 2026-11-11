#include<bits/stdc++.h>
using namespace std;
int mm[300005];
int nn[500005];
int h[300005];
bool t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nn[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			h[k]=0;
		}
		for(int f=1;f<=n;f++){
			t[f]=true;
		}
		for(int j=i;j<=n;j++){
			h[nn[j]]++;
			if(h[nn[j]]==2){
				int p=j-1;
				while(h[nn[j]]==2){
					if(t[nn[p]]==true){
						h[nn[p]]--;
						t[nn[p]]=false;
					}
					p--;
				}
			}
		}
		for(int q=1;q<=m;q++){
			mm[q]+=h[q];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}
	return 0;
}