/*
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[512345],q[512345],t[312345],ans[312345],top,tp,bl;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=m;j++) t[j]=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(int k=1;k<=top;k++){
					if(q[k]==a[j]){
						tp=k;
						break;
					}
				}for(int k=tp+1;k<=top;k++){
					t[q[k]]=0;
				}top=tp;
			}else{
				q[++top]=a[j];
				t[a[j]]=1;
			}
		}for(int j=1;j<=top;j++){
			ans[q[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
