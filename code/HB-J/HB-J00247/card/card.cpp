#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005],book[300005],t[300005],ans[300005];
int main(){
	//freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=i;
		for(int j=1;j<=book[a[i]];j++) if(t[j]<=book[a[i]]) t[j]=i;
		 book[a[i]]=i;
	}
	
	//for(int i=1;i<=n;i++) cout<<t[i]<<" ";
	//cout<<endl;
   for(int i=1;i<=n;i++){
	   for(int j=t[i];j<=n;j++){
		   ans[a[j]]++;
	   }
	   }
	   for(int i=1;i<=m;i++){
		   cout<<ans[i]<<" ";
		   }
	return 0;
	}



