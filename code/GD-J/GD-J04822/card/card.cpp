#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5; 
int a[N],c[M],b[M];
bool d[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]==2){
				for(int l=j-1;l>=1;l--){
					if(!d[l])c[a[l]]--;
					d[l]=true;
					if(a[l]==a[j])break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j])b[j]++;
			c[j]=0;
		}
		for(int i=1;i<=n;i++)d[i]=false;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
