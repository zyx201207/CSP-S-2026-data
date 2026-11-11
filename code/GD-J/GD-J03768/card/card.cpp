#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int n,m,a[500005],ans[300005],tab[500005],k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=n;i>=1;i--)st.push(a[i]);
	for(int i=1;i<=n;i++){
		int jk=1;
		while(jk<i){
			st.pop();
			jk++;
		}
		while(!st.empty()){
			int num=st.top();
			st.pop();
			int flag=0;
			for(int j=1;j<=k;j++){
				if(tab[j]==num){
					flag=j;
					break;
				}
			}
			if(flag){
				for(int j=flag;j<=k;j++){
					tab[j]=-1;
				}
				tab[++k]=num;
			}else{
				tab[++k]=num;
			}
		}
		for(int j=1;j<=k;j++){
			if(tab[j]!=-1)
				ans[tab[j]]++;
		}
		memset(tab,0,sizeof(tab));
		for(int j=n;j>=1;j--){
			st.push(a[j]);
		} 
		k=0;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

