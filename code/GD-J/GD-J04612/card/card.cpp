#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;

int a[N],b[N],c[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		int lens=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s[++lens]=a[j];
				b[a[j]]=1;
			}
			else{
				while(s[lens]!=a[j]){
					b[s[lens]]=0;
					s[lens]=0;
					lens--;
				}
			}
		}
		for(int j=1;j<=lens;j++){
			c[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
