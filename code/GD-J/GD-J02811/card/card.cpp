#include<bits/stdc++.h>
using namespace std;
int b[500010],c[500005];
long long d[500010]={},e[500005]={},a=1;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> c[i];
	for(int i=1;i<=n;i++){
		e[a]=c[i];
		d[c[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(d[c[j]]!=0){
				int a1=a;
				while(e[a]!=c[j] and a>=0){
					a--;
				}
				for(int i=a+1;i<=a1;i++){
					d[e[i]]=0;
					e[i]=0;
				}
			}else{
				a++;
				e[a]=c[j];
				d[c[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			b[j]+=d[j];
			d[j]=0;
			e[j]=0;
		}
		a=1;
	}
	for(int i=1;i<=m;i++)cout << b[i] << " ";
	return 0;
}
