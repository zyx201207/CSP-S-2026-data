#include<bits/stdc++.h>
using namespace std;
struct NODE{
	long long a;
	char s;
} p[200005];

int w=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].s;
		w+=p[i].a;
	}
	long long i=1,j=n,ans=0;
	if(n%2==1){
	while(i<n || j>1){
		int t=min(p[i].a,p[j].a);
		if(p[i].s!=p[j].s){
			ans+=t;
			if(p[i].a==t)i++;
			if(p[j].a==t)j--;
		}
		else{
			if(p[i].a==t)i++;
			if(p[j].a==t)j--;
		}
	}
	cout<<ans/2;
	}
	if(n%2==0){
	while(i!=n || j!=1){
		int t=min(p[i].a,p[j].a);
		if(p[i].s!=p[j].s){
			ans+=t;
			p[i].a-=t;
			p[j].a-=t;
			
		}
		else{
			p[i].a-=t;
			p[j].a-=t;
		}
		if(p[i].a==0)i++;
		if(p[j].a==0)j--;
	}
	cout<<ans;
	}
	return 0;
}