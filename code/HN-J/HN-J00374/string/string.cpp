#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
string c[200005];
string all1;
string all2;
string p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=1000;j++){
			p[i]+=c[i];
		}
		for(int j=1;j<=a[i]/100000;j++){
			all1+=p[i];
		}
		for(int j=1;j<=a[i]%100000;j++){
			all1+=c[i]; 
		} 
	}
	for(long long i=n;i>=1;i--){
		for(int j=1;j<=a[i]/100000;j++){
			all2+=p[i];
		}
		for(int j=1;j<=a[i]%100000;j++){
			all2+=c[i];
		}
	}
	long long ans=0;
	for(long long i=0;i<=all1.size()-1;i++){
		if(all1[i]!=all2[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
//aabbc
//cbbaa

