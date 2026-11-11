#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long t[100003];
string p;
string q;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<n;i++)q+=char(a[i]+'0');
		for(int j=0;j<n;j++){
			int z=0;
			while(z<(q[j]-'0')){
				p+=char(q[z]);
				t[q[z]-'0']++;
				z++;
			}
			p+=char(q[j]);
			t[q[j]-'0']++;
			q=p;
			p="";
		}
		for(int i=1;i<=m;i++)cout<<t[i]<<' ';
	return 0;
} 
