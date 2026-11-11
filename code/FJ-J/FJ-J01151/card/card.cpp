#include"bits/stdc++.h"
using namespace std;
int n,m,a[500005],b[500005],cx[300005],w[500005];
bool teshuA=1;
bool t[300005];
int main(){
	//40
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])teshuA=0;
		b[i]=a[i];
	}
	if(teshuA){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])
			cx[a[i]]+=i;
		}
		for(int i=1;i<=m;i++)
		cout<<cx[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(w,0,sizeof(w));
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				t[a[j]]=1;
				w[a[j]]=j;
			}else{
				for(int k=w[a[j]];k<j;k++){
					t[a[k]]=0;
					a[k]=0;
				}
				for(int k=i;k<w[a[j]];k++){
					if(a[k]!=0)
					t[a[k]]=1;
				}
				t[a[j]]=1;
			}
		}
		for(int j=i;j<=n;j++){
			cx[a[j]]++; 
		}
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	cout<<cx[i]<<" ";
	return 0;
}
/*
100+68+60+40=268 
*/
