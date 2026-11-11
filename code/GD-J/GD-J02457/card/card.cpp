#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int h=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(h<=n){
		int f=1;
		int cd[500010];
		for(int i=h;i<=n;i++){
			f++;
			for(int j=1;j<=f;j++){
				if(cd[j]==a[i]){
					for(int k=j;k<=n;k++){
						cd[k]=0;
					}
					f=j;
					break;
				}
			}
			cd[f]=a[i];
			//cout<<cd[f]<<' ';
		}
		//cout<<endl;
		for(int i=1;i<=f;i++){
			if(cd[i]!=0){
				b[cd[i]]++;
			}
			//cout<<cd[i]<<' ';
			//cout<<b[cd[i]]<<' ';
		}
		//cout<<endl;
		h++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
