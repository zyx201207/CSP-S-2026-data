#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){ 
		string s="";
		s+=(a[x]+'0');
		for(int i=x;i<=n;i++){ 
			int len=s.size();
			for(int j=0;j<len;j++){ 
				if(a[i]==a[j]){
					s="";
				}
				s+=(a[i]+'0');
			}
		}
		for(int i=0;i<s.size();i++){
			num[s[i]-'0']++; 
		}
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}
