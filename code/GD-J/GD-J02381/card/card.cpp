#include <bits/stdc++.h>
using namespace std;

int a[10000];
int ci[10000];
int paishu[10000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		paishu[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(paishu[j]==paishu[i]){
				for(int x=i;x<=j;x++){
					paishu[x]=0;
					cout<<paishu[x]
				}
			}
			if(paishu[j]!=0){
				ci[paishu[j]]+=1;
			} 
		}
		paishu[i]=a[i];
	}
	return 0;
}
