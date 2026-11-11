#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,ans,vis[211111];
string s,s1[211111],s2[211111];
bool cmp(string x,string y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin  >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a;
		int k=0;
		while (a){
			k++;
			s1[i]+=(a%2+'0');
			a/=2;
		}
		reverse(s1[i].begin(),s1[i].end());
		for (int j=1;j<=30-k;j++){
			s2[i]+='0';
		}
		s2[i]+=s1[i];
    }
    sort(s2+1,s2+n+1,cmp);
    for (int i=0;i<=29;i++){
    	int sum=0;
    	for (int j=1;j<=n;j++){
    		if (s2[j][i]=='1' && vis[j]==0){
    			sum++;
			}
		}
		if (sum>=m){
			s+='1';
			for (int j=1;j<=n;j++){
	    		if (s2[j][i]=='0'){
	    			vis[j]=1;
				}
			}
		}else{
			s+='0';
		}
	}
	int k=0;
	for (int i=29;i>=0;i--){
		if (s[k]=='1'){
			int cnt=1;
			for (int j=1;j<=i;j++){
				cnt*=2;
			}
			ans+=cnt;
		}
		k++;
	}
	cout << ans;
	return 0;
}
