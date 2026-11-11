#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],d[300005],xy[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		int qu[500005],o=0;
		for(int i=1;i<=b;i++){
			d[i]=0;xy[i]=0; 
		}
		for(int j=i;j<=a;j++){
			o++;
			d[c[j]]++;
			if(d[c[j]]==2){
				for(int ii=xy[c[j]];ii<=o;ii++){
					d[qu[ii]]=0;
				}
				o=xy[c[j]];
				d[c[j]]=1;
			}
			qu[o]=c[j];
			xy[c[j]]=o;
			
		}for(int j=1;j<=o;j++){
			ans[qu[j]]++;
		}
	}for(int i=1;i<=b;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
