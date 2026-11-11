#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}s[200005],b[200005];
long long n,ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		b[n-i+1].a=s[i].a,b[n-i+1].c=s[i].c;
		ans+=s[i].a;
	}
	long long j=1,k=1;
	for(int i=1;i<=ans/2;i++){
		if(s[j].c!=b[k].c)
			sum++;
		s[j].a--;
		b[k].a--;
		if(s[j].a==0)
			j++;
		if(b[k].a==0)
			k++;
	}
	cout<<sum;
	return 0;
}
