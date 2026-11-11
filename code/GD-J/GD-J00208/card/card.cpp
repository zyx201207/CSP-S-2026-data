#include <bits/stdc++.h>
using namespace std;

char x[500005];
int ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=m;i++){
		string s="";
		int cnt[300005]={};
		cnt[i]++;
			if(cnt[i]>1){
				while(s[s.size()-1]>x[i]){
					s.erase(s.size()-1,1);
				}
			}
			else{
				s+=x[i];
				cnt[i]=0;
			}
		for(int j=0;j<s.size();j++){
			ans[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
