#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005],d[1000005],ans[1000005],n,m,o,p;
char c;
string s,t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++) b[i]=d[i]=0;
		o=0;
		for(int i=k;i<=n;i++){
			o++;
			int x=a[i];
			if(d[x]!=0&&d[x]<o){
				for(int j=d[x]+1;j<=o;j++) d[b[j]]=0;
				o=d[x];
			}
			else{
				d[x]=o;
				b[o]=x;
			}
		}
		for(int i=1;i<=o;i++) ans[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
