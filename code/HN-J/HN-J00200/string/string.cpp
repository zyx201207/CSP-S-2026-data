#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	char x;
}a[200005];
int n;
int sz;
node j,m;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].x;
		sz+=a[i].a;
	}
	int i=1,k=n;
	j.a+=a[i].a;
	m.a+=a[k].a;
	j.x=a[i].x;
	m.x=a[k].x;
	while(i<=k){
		if(j.a>m.a){
			//cout<<"1/n";
			k--;
			if(j.x!=m.x){
				ans+=m.a;
			}
			j.a-=m.a;
			m.a=a[k].a;
			m.x=a[k].x;
		}
		else{
			i++;
			if(j.x!=m.x){
				ans+=j.a;
			}
			m.a-=j.a;
			j.a=a[i].a;
			j.x=a[i].x;
		}
	}
	cout<<ans;
}
