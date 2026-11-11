#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[20000]={0},s[200005]={0},o=0,ss=-1,aa=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=aa;j<=n-1;j++){
			o++;
			s[o]=a[i] and a[j];
		}
		aa++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]>ss){
			ss=s[i];
		}
	}
	cout<<ss;
	return 0;
}
