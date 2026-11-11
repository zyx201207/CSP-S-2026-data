#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+10]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sc[m]={};
	for(int i=1;i<=n;i++){
		int ls[n+10]={};
		for(int j=i;j<=n;j++){
			for(int p=1;p<j-i+1;p++){
				if(ls[j-i+1]==ls[p]){
					for(int q=p;q<j-i+1;q++){
						ls[q]=0;
					}
				}
			}
			ls[j-i+1]=a[j];
			
		}
		for(int j=1;j<=n;j++){
			sc[ls[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sc[i]<<" "; 
	}
	cout<<'\n';
} 
