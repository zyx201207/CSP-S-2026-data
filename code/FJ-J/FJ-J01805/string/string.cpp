#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	string b;
};
node s[200050];
long long ss[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		ss[i]=ss[i-1]+s[i].a;
		ans+=s[i].a;
	}
	long long l=1,r=ans;
	long long p=1,pp=n;
	while(l<r){
		for(int i=p;i<=n;i++){
			if(l<=ss[i]){
				p=i;
				break;
			}
		}
		for(int i=pp;i>=1;i--){
			if(r<=ss[i]){
				pp=i;
				break;
			}
		}
		if(s[p].b!=s[pp].b){
			sum+=min(s[p].a,s[pp].a);
		}
		l+=min(s[p].a,s[pp].a);
		r-=min(s[p].a,s[pp].a);
	}
	cout<<sum;
	return 0;
}
