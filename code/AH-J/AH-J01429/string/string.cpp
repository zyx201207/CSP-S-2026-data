#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],sum=0;
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}for(int l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r]){
			sum++;
		}
	}cout<<sum;
	
	
	return 0;
}

