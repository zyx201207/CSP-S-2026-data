#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,z[100005],w[100005],a[100005],s[100005];//zhuo,wei

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[i]=o;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(w[a[i]]==0){
				w[a[i]]=i;
				//z[i]=a[i];
			}else{
				for(int j=w[a[i]];j<=i;j++){
					w[a[j]]=0;
					//z[i]=0;
				}
				w[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(w[i]!=0){
				s[i]++;
			}
			w[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
}
