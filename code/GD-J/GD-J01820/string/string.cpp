#include<bits/stdc++.h> 
using namespace std;
long long n,c,cnt;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		char b;
		cin>>b;
		for(int j=0;j<c;j++){
			a+=b;
		}
	}
	for(long long i=0;i<a.size()*1.0/2;i++){
		if(a[i]!=a[a.size()-i]){
			cnt++;
		}
	}
	
	cout<<cnt-1;
	return 0;
}
