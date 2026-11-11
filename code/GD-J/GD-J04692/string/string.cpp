#include<bits/stdc++.h>
using namespace std;
string s1;
int n,cnt,x,ans;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s1+=a;
		}
		cnt+=x;
	}
	for(int i=0;i<cnt/2;i++) if(s1[i]!=s1[cnt-i-1]) ans++;
	cout<<ans;
	return 0;
} 
