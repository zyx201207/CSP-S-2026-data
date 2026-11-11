#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
string s,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			bool flag=1,pos;
			for (int k=0;k<x.size();k++) if (x[k]==s[j]) flag=0,pos=k;
			if (x.size()==0 || flag){
				x+=s[j];
			}else{
				for (int k=pos;k<x.size();k++){
					x[k]=0;
				}
				x+=s[j];
			}
		}
		for (int j=0;j<x.size();j++){
			if (x[j]!=0){
				int v=x[j]-'0';
				a[v]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
