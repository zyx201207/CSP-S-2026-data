#include<bits/stdc++.h>
using namespace std;
int z,x;
long long maxx;
struct sz{
	long long a;
	string b;
}c[100010];
bool cmp(sz q,sz w){
	return q.a<w.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>z>>x;
	for(int i=1;i<=z;i++){
		cin>>c[i].a;
		maxx=max(maxx,c[i].a);
	}
	if(x==1){
		cout<<maxx;
		return 0;
	}else if(x==z){
		for(int i=2;i<=z;i++){
			c[i].a=(c[i].a)&(c[i-1].a);
		}
		cout<<c[z].a;
	}
return 0;
}
