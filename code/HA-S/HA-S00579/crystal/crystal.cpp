#include<bits/stdc++.h>
using namespace std;
int m,n,t=1,num=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
int s1[n+1];
int ans[n];
for(int i=1;i<=n;i++){
	cin>>s1[i]; 
	num+=s1[i];
	}
num/=n;
for(int i=1;i<=n;i++){
	if(s1[i]>=num) ans[i]=s1[i]-num;
	if(s1[i]<num)  ans[i]=num-s1[i];
}
sort(ans+1,ans+n);
for(int i=1;i<=n;i++){
	if(m>=ans[i])
	{
	m-=ans[i];
	t++;
	if(m<ans[i]) break;}
}
cout<<t<<endl;

	
	return 0;}
