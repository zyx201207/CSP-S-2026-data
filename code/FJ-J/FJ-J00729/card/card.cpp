#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		string s;
		for(int j=i;j<=n;j++){
			if(s.find(a[j]+'0')!=string::npos){
				int x=s.find(a[j]+'0');
				s.erase(x);
			}
			s+=(a[j]+'0');
		}
		for(int j=0;j<s.size();j++) cnt[s[j]-'0']++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]); 
	return 0;
}
