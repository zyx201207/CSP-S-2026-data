#include<bits/stdc++.h>
using namespace std;
int n,m;
struct V{
	int a;
	int p;
	int c;
}t[500005];
V b[500005];
int v[500005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		t[i].c=i;
		if(b[t[i].a].a!=0){
			t[i].p=b[t[i].a].p;	
		}
		b[t[i].a].a=1;
		b[t[i].a].p=i;
	}
	for(int i=1;i<=n;i++){
		if(t[i].p!=0){
			for(int j=t[i].p;j<i;j++){
				t[j].c-=t[i].p;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i].c>0){
			v[t[i].a]+=t[i].c;
		}
	}
	for(int i=1;i<=m;i++){
//		if(v[i]<0){
//			cout<<0;
//		}
//		else{
//			cout<<v[i];
//		}
		cout<<v[i]<<" ";
	}
	return 0;
}
