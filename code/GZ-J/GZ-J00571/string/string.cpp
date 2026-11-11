//GZ-J00571 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
int n,a,k,ans;
char b;
char c[1000000005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			c[++k]=b;
		}
	}
	bool f=((k%2==1)? 0:1);
	int mid=k/2;
	for(int i=1;i<=mid;i++)
		if(c[i]!=c[k-i+1]) ans++;
	cout<<ans;
	return 0;
}
