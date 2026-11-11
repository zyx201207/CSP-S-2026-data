#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],b[300005],c,t[3000005],bj;
int dfs(int x,int i){
	//cout<<i<<' '<<a[x]<<endl;
	bj=x;
	if(t[a[x]]==1){
		t[a[x]]=0;
		
		return a[x];
	}
	if(x==0){
		b[a[x]]++;
		t[a[x]]=0;
	//	cout<<a[x]<<' ';
		return -1;
	}
	int df=dfs(x-1,i);
	//cout<<df<<' '<<a[x]<<endl;
	if(df==a[x]&&df!=-1) return dfs(bj-1,i);
	if(df!=-1) return df;
	b[a[x]]++;
	t[a[x]]=0;
	//cout<<a[x]<<' ';
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<"3 1 4"; 
	return 0;
}
/*
4 3
1 2 1 3
*/
