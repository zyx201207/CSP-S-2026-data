#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000],cnt,m=1,sum=0;
char c[1000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s[m]=c[i];
			m++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(cnt%2==0){
		for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[cnt-i+1]) sum++;
		}
	}
	else if(cnt%2==1){
		for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[cnt-i+1]) sum++;
		}
	}
	cout<<sum;
	return 0;
}

