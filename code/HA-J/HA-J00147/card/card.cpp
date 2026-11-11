#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[m+5]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		set<int>c;
		string s;
		for(int j=i;j<=n;j++){
			if(c.count(a[j])){
				for(int k=0;k<s.size();k++){
					if(s[k]-'0'==a[j]){
						s.erase(k,s.size()-k);
						break;
					}
				}
			}
			c.insert(a[j]);
			s+=char(a[j]+'0');
		}
		for(int j=0;j<s.size();j++){
			b[int(s[j]-'0')]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
