#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,a[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string w=""; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
		for(int j=1;j<=a[i];j++) w+=c[i];
 	}
 	for(int i=0;i<w.size();i++){
		if(w[i]!=w[w.size()-i-1]){
			ans++;
			w[i]=w[w.size()-i-1];
		}
	}
	cout<<ans;
	return 0;
}
