#include<bits/stdc++.h>
using namespace std;
int main {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,x=0,y=0,sum=0;
	char s[200001];
	cin>>n;
	int a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++){
			s[x+i]=c[i];
		}
		x+=a[i];
	}
	if(x%2==1){
		y=x/2+1;
	}
	for(int i=1;i<=n;i++){
		if(i==y){
			continue;
		}
		if(s[i]!=s[x+1-i]){
			s[x+1-i]=s[i];
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
