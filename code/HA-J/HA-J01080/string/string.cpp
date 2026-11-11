#include<bits/stdc++.h>
using namespace std;
struct N{
	int a;
	char b;
}q[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int s=0;
	for(int i=0;i<n;i++){
		cin>>q[i].a>>q[i].b;
	}
	n--;
	while(n!=s){	
		int o=min(q[n].a,q[s].a);
		if(q[n].b!=q[s].b)
			ans+=o;
		q[n].a-=o;
		q[s].a-=o;
		if(q[n].a==0)
			n--;
		else
			s++;					
	}
	cout<<ans;
}

