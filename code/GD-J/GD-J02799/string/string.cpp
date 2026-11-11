#include<bits/stdc++.h>
using namespace std;
struct p{
	int a;
	char b;
}cn[200005];
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>cn[i].a;
		cin>>cn[i].b;
	}
	while(l<r){
		if(cn[l].a==0)l++;
		if(cn[r].a==0)r--;
		int t=min(cn[l].a,cn[r].a);
		cn[l].a-=t;
		cn[r].a-=t;
		if(cn[l].b!=cn[r].b){
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
