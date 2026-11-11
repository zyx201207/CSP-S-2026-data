#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005],res;
int find_x(int x){
	for(int i=1;i<=res;i++){
		if(t[i]==x)return i;
	} 
	return 0;
}
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(find_x(a[j])==0){
				t[++res]=a[j];
			}		
			else{
				int t2=find_x(a[j]);
				for(int k=t2;k<=res;k++){
					t[k]=0;		
				}	
				res=t2-1;
				t[++res]=a[j];
			}
		}
		for(int j=1;j<=res;j++){
			cnt[t[j]]++;	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
