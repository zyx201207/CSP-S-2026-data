#include<bits/stdc++.h>
using namespace std;

struct Zack{
	long long number;
	char latter;
}a[200100];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].number>>a[i].latter;
	int p=n;
	for(int i=1;i<p;i++){
		while(a[i].number!=0){
			int now=min(a[i].number,a[p].number);
			if(a[i].latter!=a[p].latter)
				ans+=now;
			a[i].number-=now;
			a[p].number-=now;
			if(a[p].number==0)
				p--;
			if(i==p){
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
