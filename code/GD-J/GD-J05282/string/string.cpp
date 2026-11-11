#include<bits/stdc++.h>
using namespace std;
long long n,b,sum,L;
char c;
string a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		while(b--)a+=c;
	}
	L=a.size();
	for(int i=0;i<L/2;i++){
		if(a[i]!=a[L-1-i])sum++;
	}
	cout<<sum;
	return 0;
}
