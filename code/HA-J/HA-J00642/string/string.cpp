#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b=0,uu=1;long long ans=0;//¶ÎÊý  
	cin>>a;
	int d[a+1];
	char c[a+1];
	for(int i=1;i<=a;i++){
		cin>>d[i]>>c[i];
		b+=d[i];
	}
	char t[b+2];
	for(int i=1;i<=a;i++){
		for(int j=1;j<=d[i];j++){
		t[uu]=c[i];uu++;
	}}
	if(b%2==1){
		for(int i=1;i<=b/2;i++)if(t[b/2-(i-1)]!=t[b/2+i])ans++;
	}
	else{
		for(int i=1;i<=b/2;i++)if(t[(b+1)/2+1]!=t[(b+1)/2-1])ans++;
	}
	cout<<ans;
	return 0;
}
