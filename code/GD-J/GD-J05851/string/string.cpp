#include<bits/stdc++.h>
using namespace std;
long long n,x[200005],sum,ans,num;
char y[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1,j=n;i<j;){
		num=min(x[i],x[j]);
		if(y[i]!=y[j]) ans+=num;
		x[i]-=num;
		x[j]-=num;
		if(x[i]==0) i++;
		else j--;
	}
	cout<<ans;
	return 0;
} 

