#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[1000000];
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	int jsh[1000004]={0};
	for(int i=1;i<=n;i++){
		int map[10000]{0},o=0;
	for(int j=i;j<=n;j++){
		
		
		for(int l=o;l>=1;l--){
			if(map[l]==a[j]){
				for(int p=l+1;p<=o;p++)map[p]=0;
				o=l;
				break;
			}else map[o+1]=a[j],o++;
			}
			
			
		}
		for(int u=1;u<=o;u++)cout<<map[u]<<' ';
		cout<<endl;
		for(int u=1;u<=o;u++)jsh[map[u]]++;
	}
	for(int i=1;i<=m;i++)cout<<jsh[i]<<' ';
	return 0;
}
