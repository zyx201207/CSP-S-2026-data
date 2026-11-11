#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[200000000000001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int k=1;
	int h=0;
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		char c;
		cin>>c;
		for(int j=k;j<=k+z-1;j++){
			s[j]=c;
		}
		k+=z;
		h+=z;
	}
	int sum=0;
	for(int i=1,j=h;i<=j;i++,j--){
		if(s[i]!=s[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
