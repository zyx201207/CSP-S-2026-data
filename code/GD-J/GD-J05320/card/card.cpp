#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500010],b[300010],front,tail;
long long s[500010];
bool vis1[300010],vis2[300010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis2[j]){
				if(vis1[a[j]]){
					while(s[tail]!=a[j]){
						tail--;
						vis2[s[tail]]=1;
					}
					s[tail++]=a[j];
				}
				else{
					s[tail++]=a[j];
					vis1[a[j]]=1;
				}
			}
			else continue; 
		}
		for(int j=0;j<tail;j++){
			b[s[j]]++;
		}
		memset(vis1,0,300010);
		memset(vis2,0,300010);
		front=0;
		tail=0;
	}
	
	for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
	
	return 0;
}
