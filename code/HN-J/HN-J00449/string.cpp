#include<bits/stdc++.h>
using namespace std;
string a;
long long cnt=0,s=0,c=0;
void abc(int n){
	if(n>s/2){
		if(cnt>c){
			c=cnt;
		}
		return ;
	}
	if(a[n]!=a[s-n+1]){
		char b=a[s-n+1];
		a[s-n+1]=a[n];
		cnt++;
		return abc(n+1);
		cnt--;
		a[s-n+1]=b;
		a[n]=a[s-n+1];
		cnt++;
		return abc(n+1);
		cnt--;
	}
	else{
		return abc(n+1);
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(long long j=1;j<=b;j++){
			a[++s]=c;
		}
	}
	abc(1);
	cout<<c;
	return 0;
}
