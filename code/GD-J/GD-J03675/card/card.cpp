#include<bits/stdc++.h>
using namespace std;
int a[500001]={};
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	int b[m+1]={};
	for(int j=1;j<=m;j++){
			b[j]=0;
		}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int appear[m+1],first[m+1];
		for(int j=1;j<=m;j++){
			appear[j]=0;
			first[j]=0;
		}
		int s[n+1];
		s[n+1]=a[i];
		appear[a[i]]+=1;
		if(appear[a[i]]==2){
			appear[a[i]]=0;
			int t=first[a[i]];
			while(s[t+1]!=a[i]){
				s[t]=0;
				t++;
			}
			s[t]=0;
		}
		else first[a[i]]=i;
		for(int k=1;k<=n;k++){
			b[s[k]]+=1;
		}
	}
	for(int j=1;j<=m;j++){
			cout<<b[j]<<" ";
		}
	return 0;
}
