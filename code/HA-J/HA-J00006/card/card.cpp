#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],cnt=1,c[300005];
	string b="";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(cnt==n){
		for(int i=cnt-1;i<n;i++){
			for(int j=0;j<b.size();j++){
				if(a[i]==b[j]){
					for(int k=j;k<b.size();k++){
						b[k]='';
					}
				}
			}
		}b+=a[i];
	}for(int i=1;i<=m;i++){
		for(int j=0;j<b.size();j++){
		if(b[j]==i) c[i]++
		}
	}for(int i=0;i<m;i++){
		cout<<c[i];
	}
	
	
	return 0;
}
