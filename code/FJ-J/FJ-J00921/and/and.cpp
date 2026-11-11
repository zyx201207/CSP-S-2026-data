#include <bits/stdc++.h>
using namespace std;
long long a[200010];
string t[200010];
int id[30][200010],num[30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long s=a[i];
		char c[30];
		for(int j=29;s>0 || j>=0;j--){
			c[j]=s%2+'0';
			s/=2;
		}
		t[i]=c;
	}
	sort(t+1,t+n+1);
	for(int i=0;i<=29;i++){
		for(int j=1;j<=n;j++){
			if(t[j][i]=='1'){
				id[i][++num[i]]=j;
			}
		}
	}
	for(int i=0;i<=29;i++){
		if(num[i]>=m){
			string s=t[num[i]];
			for(int j=num[i]-1;j>=num[i]-m+1;j--){
				for(int k=0;k<30;k++){
					if(s[k]!=t[id[i][j]][k]) s[k]='0';
				}
			}
			long long k=0,c=1;
			for(int j=29;j>=0;j--){
				c*=2;
				if(s[j]=='1') k+=c/2;
			}
			cout << k;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
