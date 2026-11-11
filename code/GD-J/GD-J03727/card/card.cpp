#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],js[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string s="";
		bool ok[300010];
		memset(ok,false,sizeof(ok));
		for(int j=i;j<=n;j++){
			int c=s.find(char(a[j]+'0'));
			if(c!=-1){
				int l=s.size();
				string b="";
				for(int k=0;k<=c;k++){
					b+=s[k];
				}
				s=b+char(a[j]+'0'); 
			}
			else s+=char(a[j]+'0');
		}
		for(int j=0;j<s.size();j++){
			ok[s[j]-'0']=true;
		}
		for(int j=1;j<=m;j++){
			if(ok[j]) js[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<js[i]<<" ";
	return 0;
} 
