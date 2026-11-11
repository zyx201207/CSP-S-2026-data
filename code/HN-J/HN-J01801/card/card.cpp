#include<bits/stdc++.h>
using namespace std;
int n,m,num[300000];
int kards[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>kards[i];
	}
	for(int i=0,S,E;i<n;i++){
		S=i;E=i;
		int seat[300000];
		for(int j=i;j<n;j++){
			if(seat[kards[j]]>=S)
				S=j;
			E=j;seat[kards[j]]=j;
		}
		for(int j=S;j<=E;j++)
			num[kards[j]]++;
	}
	for(int i=0;i<m;i++)
		cout<<num[m]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
