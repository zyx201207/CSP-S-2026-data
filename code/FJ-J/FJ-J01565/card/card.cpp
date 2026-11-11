#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010],v[300010];
string s="",s1="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			s1="";
			for(int k=0;k<s.size();k++){
				if(s[k]-'0'==a[j]){
					s=s1;
					break;
				}s1+=s[k];
			}s+=(a[j]+'0');
		}
		for(int j=0;j<s.size();j++){
			b[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
