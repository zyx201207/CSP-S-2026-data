#include <bits/stdc++.h>
using namespace std;
string a,m;
bool n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b,sum=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		for(int j=1;j<=b;j++) a+=c;
	}
	for(int i=a.size()-1;i>=0;i--){
		m+=a[i];
	}
	
	if(a==m){
		cout<<0;
		return 0;
	}else{
		int cnt=a.size();
		for(int i=0;i*i<a.size();i++){
			if(a[i]!=a[cnt]) sum++;
			cnt--; 
		}
	}
	cout<<sum;
	return 0;
}
