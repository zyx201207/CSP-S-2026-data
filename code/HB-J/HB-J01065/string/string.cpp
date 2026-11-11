#include<bits/stdc++.h>
using  namespace std;
queue<char> q;
int n,s,cnt,ans;
char c,a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s>>c;
		a[++cnt]=c;
	}
	for(int i=1,j=cnt;i<=j;i++,j--){
		if(a[i]!=a[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
