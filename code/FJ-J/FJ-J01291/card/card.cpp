#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k[maxn];
	int ans[maxn];
	int now[maxn];
	for(int i=1;i<=n;i++){
		int p=i;
		int r=i;
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				k[a[j]]=1;
				now[p]=a[j];
				p++;
			}
			else{
				for(int g=1;g<=m;g++){
					k[g] = 0;
				}
				now[p]=a[j];
				k[a[j]] = 1;
				r=p;
				p++;
			}
		}
		for(int j=r;j<=n;j++){
			ans[now[j]] +=1;
			cout<<now[j]<<" ";
		}
		for(int g=1;g<=m;g++) k[g]=0;
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
}
