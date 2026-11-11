#include<bits/stdc++.h>
using namespace std;
int main(){
	int e=0,n,m,s[500001],d[300001];
	cin>>n>>m;
	e=n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){//¾ÖÊý 
		for(int j=i;j<=n;j++){
			for(int y=j+1;y<=n;y++){
				if(s[y]==s[j]){
					e=e-y+j;
					int l1=j+1;
					for(int l=y+1;l<=n;l++){
						s[l1]=s[l];
						l1++;
					} 
				}
			}
		}
		for(int x=i;x<=e;x++){
			d[s[x]]++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<d[i];
	}

	return 0;
}
