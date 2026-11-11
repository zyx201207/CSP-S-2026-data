#include<bits/stdc++.h>
#define ll long long
using namespace std;
string z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			z+=b;
		}
	}
	ll sum=0;
	for(int i=0,j=z.length()-1;i<z.length(),j>=0;i++,j--){
		if(i<j){
			if(z[i]!=z[j]){
				sum++;
			}
		}else{
			break;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
