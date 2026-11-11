#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005];
char a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		string s;
		for(int i=l;i<=n;i++){
			for(int j=0;j<s.size();j++){
				if(s[j]==a[i]){
					for(int k=j;k<s.size();k++){
						s[k]='0';
					}
				} 
			}
			s+=a[i];
		}
		for(int i=0;i<s.size();i++){
			if(s[i]!='0'){
				b[int(s[i])-48]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
