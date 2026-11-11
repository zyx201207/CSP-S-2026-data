#include<bits/stdc++.h>
using namespace std;
long long l,r,n,zsc;
struct ss{
	long long a;
	char c;
} sz[200005];
void tz(){
	if(sz[l].a>sz[r].a){
		sz[l].a-=sz[r].a;
		r--;
		return ;
	}
	if(sz[l].a<sz[r].a){
		sz[r].a-=sz[l].a;
		l++;
		return ;
	}
	if(sz[l].a==sz[r].a){
		l++;
		r--;
		return ;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sz[i].a>>sz[i].c;
	}
	l=1;
	r=n;
	while(l<r){
		if(sz[l].c==sz[r].c){
			tz();
		}else{
			zsc+=min(sz[l].a,sz[r].a);
			tz();
		}
	}
	cout<<zsc;
	return 0;
}
