#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b[1000011],cc[1000011],dd,e,f[1000011],g,m,n;
string c,d;
void aaa(int j){
	
	if(c.find((char)(b[j]+48))<1e8){
				d="";dd=0;
				while(c[dd]!=(b[j]+48)){
					d+=c[dd];dd++; 
				}c=d;
				c+=(char)(b[j]+48);
			}else{
				c+=(char)(b[j]+48);
			}
			return; 
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=n;i++){
c="";
		for(int j=i;j<=n;j++){
aaa(j);
		}	
		for(int i=0;i<c.size();i++){
		f[c[i]-48]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
}
