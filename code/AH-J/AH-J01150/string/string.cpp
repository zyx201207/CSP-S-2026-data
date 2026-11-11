#include<bits/stdc++.h>
using namespace std;
struct node{
	long long int a;
	char c;
}q[200005];
long long int cnt=0,now=0,now1=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,m=0;
	cin>>n;
	string d="";
	int m=0;
	for(long long int i=1;i<=n;i++){cin>>q[i].a>>q[i].c;
		if(q[i].a>ma)ma=q[i].a;
		for(int j=1;j<=q[i].a;j++)
		{
			d+=q[i].c;
		}
		cnt+=q[i].a;}
		if(ma<1000){
	for(int i=0;i<=cnt/2;i++)
	{
		if(d[i]!=d[n-i+1])ans++;
	}
	cout<<ans;
}
	else {
		cnt=0,now=0,now1=0,ans=0;
	long long int o=0;
	for(long long int i=1;i<=n;i++){
		if(o!=0)ans+=o;
		if(o<0)q[i].a+=o;
		if(o>0)q[n-i+1].a+=o;
		if(q[i].c!=q[n-i+1].c && now<cnt/2 && now1<cnt/2)ans+=min(q[i].a,q[n-i+1].a);
		if(q[i].c!=q[n-i+1].c && (now>=cnt/2 || now1>=cnt/2)){
			ans+=(now+now1-cnt)/2;
			
		}
		o=q[i].c-q[n-i+1].c;
		now1+=q[i].a;
		now=now+q[n-i+1].a;
	}
	cout<<
}
	return 0;
}




