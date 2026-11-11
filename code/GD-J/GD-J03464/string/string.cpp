#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,sum=0;
char s[20000010];
char s1;
signed main(){
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>s1;
		for(int j=0;j<a;j++){
			s[b]=s1;
			b++;
		}
	}
	int l=0,r=b-1;
	while(l<r){
		if(s[l]!=s[r]){
			sum++;
		}
		l++;
		r--;
	} 
	cout<<sum;
	return 0;
}
