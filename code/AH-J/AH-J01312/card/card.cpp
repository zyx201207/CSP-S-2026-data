#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[500010];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=1;
			string ss=to_string(a[i]);
			for(int k=0;k<int(s.size());k++){
				if(f==0){
					s[i]=' ';
					continue;
				}
				if(s[i]==ss[0]) f=0;
			}
			s+=to_string(a[i]);
		}
		for(int j=0;j<int(s.size());j++) cnt[int(s[i]-'0')];
		s="";
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
