#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
char c,s[2*N];
bool f=true;
long long m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	char c3;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		if(i==1)c3=c;
		if(f==true&&i>=2){
			if(c!=c3)f=false;
		}
		for(long long j=m+1;j<=m+a[i];j++){
			s[j]=c;
		}
		m+=a[i];
	}
	if(n<=1||f==true){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m+1-i])ans++;
	}
	cout<<ans;
	return 0;
}
