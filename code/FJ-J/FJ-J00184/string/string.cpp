#include <iostream>
#include <cstring>
using namespace std;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		string l;
		cin>>k>>l;
		for(int i=1;i<=k;i++){
			a+=l;
		}
	}
	long long ans=0;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
