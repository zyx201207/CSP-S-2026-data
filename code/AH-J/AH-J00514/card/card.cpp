#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],l=1,o[300005],v;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    while(l<=n){
    for(int i=l;i<=n;i++){
    if(b[a[i]]==1){
    for(int j=1;j<=i;j++){
    b[a[j]]=0;
    }
    b[a[i]]=1;
    }
    else{
    b[a[i]]=1;
    }
    }
    for(int i=l;i<=n;i++){
		if(b[a[i]]==1){
			c[a[i]]++;
			b[a[i]]=0;
		}
	}
	l++;
    }
    for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
return 0;
}
