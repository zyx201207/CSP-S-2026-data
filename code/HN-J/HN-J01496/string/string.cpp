#include<iostream>
#include<cstring>
using namespace std;
string r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,f=0,ans=0;
	cin >> n;
	for(int q=0;q<n;q++){
		int a;
		cin >> a;
		string x;
		cin >> x;
		for(int w=0;w<a;w++){
			r+=x;
		}
		f+=a;
	}
	long long p=f/2+f%2;
	f/=2;
	for(int u=f-1;u>=0;u--){
		if(r[u]==r[p]){
		}else{
			ans++;
		}
		p++;
	}
	cout << ans;
	return 0;
}
