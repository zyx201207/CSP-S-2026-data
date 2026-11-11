#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e9+5;
int n,x;
long long s,z=1;
char a,b[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>a;
		for(int i=z;i<=z+x;i++){
			b[i]=a;
		}
		z+=x;
	}
	z--;
	for(int i=1;i<=z;i++){
		if(b[i]==b[z-i+1])continue;
		else s++;
	}
	cout<<s/2;
	return 0;
}
