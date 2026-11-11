#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],b[200100],bn=1,b1,b2,cnt;
char c[200100];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i]+b[i-1];
		for(int j=1;j<=a[i];j++){
			s[bn]=c[i];
			bn++;
		}
	}for(int i=1;i<=b[n]/2;i++){
		if(s[i]!=s[b[n]-i+1]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
