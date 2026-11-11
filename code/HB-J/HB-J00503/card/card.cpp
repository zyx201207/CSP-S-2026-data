#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],b[300007],c[500007],v[300007],step=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(v[a[j]]!=0){
				int l=v[a[j]];
				for(int i=l;i<=step;i++){
					v[c[i]]=0;
					c[i]=0;
				}
				step=l;
			}
			c[step]=a[j];
			v[a[j]]=step;
			step++;
			/*for(int k=1;k<=4;k++) cout<<c[k];
			cout<<endl;
			for(int k=1;k<=4;k++) cout<<v[k];
			cout<<endl<<endl;*/
		}
		for(int j=1;j<=step-1;j++) b[c[j]]++;
		step=1;
		memset(c,0,sizeof(c));
		memset(v,0,sizeof(v));
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
