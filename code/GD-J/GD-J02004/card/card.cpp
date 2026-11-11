#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+10;
int mark[N];
int a[N];
int b[N];
int main(){
	//±©Á¦ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mark[a[j]]==0){
				mark[a[j]]=j;
			}
			else{
				for(int l=mark[a[j]];l<j;l++){
					mark[a[l]]=0;
				}
			}
			mark[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(mark[j]!=0){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
