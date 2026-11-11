#include<bits/stdc++.h>
using namespace std;
string a[400005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,sum=0,cnt=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s;
		cnt+=m;
		for(int i=1;i<=m;i++){
			a[i]=s;
		}
	}
	for(int i=1;i<=cnt-i;i++){
		if(a[i]!=a[cnt-i+1]) sum++;
	}
	cout<<sum;
}
