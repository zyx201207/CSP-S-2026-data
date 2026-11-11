#include<bits/stdc++.h>
using namespace std;
int n  ;
long long a[200001] ;
char c[200001] ;
long long n1 ;
char s[100000001] ;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int num=0 ;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		n1+=a[i];
		for(int j=1;j<=a[i];j++){
			num++;
			s[num]=c[i];
		}
	}
	n1/=2;
	long long ans=0 ;
	for(int i=1;i<=n1;i++){
		if(s[i]!=s[num+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
