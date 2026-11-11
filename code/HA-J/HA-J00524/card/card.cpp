#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],k[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","l",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		string s="",z="";
		for(int j=i;j<=n;j++){
			int b=s.find(char(a[j]+'0'));
			if(b==-1){
				s+=char(a[j]+'0');
			}
			else{
				for(int o=0;o<=b;o++){
					z+=s[o];
				}
				s=z;
				z="";
			}
		}
		for(int j=1;j<=m;j++){
			int c=s.find(char(j+'0'));
			if(!(c==-1)){
				k[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<k[i]<<" ";
	return 0;
}
