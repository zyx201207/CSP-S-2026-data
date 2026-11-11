#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
map<long long,char>s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long last=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=last;j<=a[i]+last;j++){
			s[j]=c[i];
		}
		last+=a[i];
	}
	last--;
	long long sum=0;
	for(int i=1;i<=last/2;i++){
		if(s[i]!=s[last+1-i]){
			s[i]=s[last+1-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
