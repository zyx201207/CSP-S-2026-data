#include<bits/stdc++.h> 
using namespace std;
int n;
long long m[200010],len=0,ans=0;
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
		len+=1ll*m[i];
	}
	cout<<len/2;
	return 0;
}
