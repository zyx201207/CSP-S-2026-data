#include<bits/stdc++.h>
using namespace std;
int n,m;
long long v;
struct V{
	long long a;
	int w;
}t[200005];
bool cmp(V &x,V &y){
	if(x.w==y.w){
		return x.a>y.a;
	}
	else{
		return x.w>y.w;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		int l=t[i].a;
		while(l!=0){
			l=l>>1;
			t[i].w++;
		}
	}
	sort(t+1,t+1+n,cmp);
	v=t[1].a;
	for(int i=2;i<=m;i++){
		v&=t[i].a;
	}
//	for(int i=1;i<=n;i++){
//		if(t[i].w<z-1){
//			break;
//		}
//		for(int j=i+1;j<=n;j++){
//			if(t[j].w<z-1){
//				break;
//			}
//			v=max(v,t[i].a&t[j].a);
//		}
//	}
	cout<<v;
	return 0;
}
