#include<bits/stdc++.h>
using namespace std;
long long ans,l=1,r;
long long n;
struct shq{
	long long a;
	char c;
}q[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
	}
	while(l<r){
		if(q[l].c!=q[r].c){
			if(q[l].a>q[r].a) q[l].a-=q[r].a,ans+=q[r].a,r--;
			else if(q[l].a==q[r].a) ans+=q[l].a,l++,r--;
			else q[r].a-=q[l].a,ans+=q[l].a,l++;
		}
		else{
			if(q[l].a>q[r].a) q[l].a-=q[r].a,r--;
			else if(q[l].a==q[r].a) l++,r--;
			else q[r].a-=q[l].a,l++;
		}
	}
	cout<<ans;
	return 0;
}
