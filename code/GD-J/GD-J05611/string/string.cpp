#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>b;
		while(m--)a+=b;
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i])sum++;
	}
	
	cout<<sum;
	
	return 0;
}
