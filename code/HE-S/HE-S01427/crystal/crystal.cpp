#include <bits/stdc++.h> 
using namespace std;
int a[500005],a1[500005],b[500005],t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,y=1,p=0,q,tm,mx;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		a1[i]=a[i]-a[i-1];
	}for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(j==1){
				q=a1[i];
			}
			if(q<=m){
				q+=a1[j+y];
				x++;
			}
		}b[i]=x;
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i]==b[j]) t[i]+=1;
		}if(i==1){
			tm=t[i];
			mx=i;
		}if(t[i]>=tm){
			tm=t[i];
			mx=i;
		} 
	}cout<<b[mx];
	return 0;
}
