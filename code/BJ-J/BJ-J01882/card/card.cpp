#include <bits/stdc++.h>
using namespace std;
int a,b,c[300001],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>d[i];
	for(int i=1;i<=a;i++){
		int e[500005],ll;
		for(int j=i;j<=a;j++){
			bool has=0;
			int oi=-1;
			for(int k=0;k<ll;k++) if(e[k]==d[j]){has=1;oi=k;}
			if(has){
				int l=ll;
				for(int k=oi+1;k<l;k++){
					e[k]=0;
					ll--;
				}
			}
			else{
				e[ll]=d[j];
				ll++;
			}
		}
		for(int j=0;j<ll;j++) c[e[j]]++;
		for(int j=0;j<ll;j++) e[j]=0;
		ll=0;
	}
	for(int i=1;i<=b;i++) cout<<c[i]<<" ";
}
