#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],t[300005],b[500005],cnt;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			int x=b[k];
			int y=cnt;
			for(int j=1;j<=n;j++){
				if(a[j]==0){
					if(y==cnt){
						cnt++;
					}
					break;
				}
				if(a[j]==x){
					cnt=j;
				}
				if(j>=cnt){
					a[j]=0;
				}
			}
			a[cnt]=x;
		}
		for(int k=1;k<=n;k++){
			if(a[k]==0){
				break;
			}else{
				t[a[k]]++;
			}
			a[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i]!=0){
			cout<<t[i];
		}
	}
	return 0;
}
