#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],h;
string v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n;
	for(int i=0;i<n;i++){
		char aa;
		cin>>aa>>a[i];
		for(int j=0;j<a[i];j++){
			v+=aa;
		}
		m+=a[i];
	}
	for(int i=0,j=m-1;i<j;i++,j--){
		if(v[i]!=j[i])h++;
	}
	
	return 0;
} 
