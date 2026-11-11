#include<bits/stdc++.h>
using namespace std;
int d[100][1000]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,m=0;
	
	cin>>a>>b;
	int g[a];
	for(int i=1;i<=a;i++){
		cin>>g[i];
	}
	for(int i=1;i<=a;i++){
		for(int p=i+1;p<=a;p++){
			if(d[i][p]==0&&d[p][i]==0){
				if(m<g[i]&g[p]) m=g[i]&g[p];
				d[i][p]=1;
			}
		}
	}
	cout<<m;
}
