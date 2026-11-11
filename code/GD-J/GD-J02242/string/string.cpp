#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		char y;
		cin>>y;
		while(x--){
			a+=y;
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	//long long z=(a.size()+1)
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			b[i]=a[i];
			a[a.size()-1-i]=a[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
