#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,x,cnt;
char a,s1[3000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		x+=m;
		for(int j=1;j<=m;j++){		
			s1[ans]=a;
			ans++;			
		}
	}
	for(int i=1;i<=x/2;i++){		
		if(s1[i]!=s1[x-i+1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
