#include<bits/stdc++.h>
using namespace std;
string a;
long long d42=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long s;
		string b;
		cin>>s>>b;
		while(s--) a=a+b;
	}
	for(int i=0;i<=a.size()-1;i++){
		long long j=a.size()-i-1;
		if(j<=i){
			break;
		}
		if(a[i]!=a[j]){
			d42++;
		} 
		
	}
	
	cout<<d42;
	return 0;
	
}
