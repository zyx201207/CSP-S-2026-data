#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
const int MAXM=300010;
int a[MAXN];
int n,m;
int table[MAXM],top,card[MAXM];
int ans[MAXM];
int find(int x){
	if( card[x]<=top && card[x]>0 && table[card[x]]==x  ){
		return card[x];
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	//freopen("E:\\cspj\\down\\card\\card6.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			int k=find(a[j]);
			if(k){
				top=k;
			}
			else{
				table[++top]=a[j];
				card[a[j]]=top;
			}
		}
		for(int j=1;j<=m;j++){
			if(find(j)){
				ans[j]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
