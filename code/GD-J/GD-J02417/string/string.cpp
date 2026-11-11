#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	char c;
	int f;
};
struct local{
	int w,m;
};
int n,ans,h;
node a[200010];
int main(){
//	freopen(cin,"r");
//	freopen(cout,"p");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].c;
		a[i].f=0;
	}
	local p,q;
	p.w=1;
	q.w=n;
	p.m=0;
	q.m=0;
	while(q.w>=p.w){
		if(a[p.w].c!=a[q.w].c){
			if(a[p.w].n-a[p.w].f==a[q.w].n-a[q.w].f){
				ans+=a[p.w].n;
				a[p.w].f=a[p.w].n;
				p.w++;
				q.w--;
				if(a[p.w].n-a[p.w].f<=p.m){
					p.m-=a[p.w].n-a[p.w].f;
					p.w++;
				}
				if(a[q.w].n-a[q.w].f<=q.m){
					q.m-=a[q.w].n-a[q.w].f;
					q.w++;
				}
			}else if(a[p.w].n-a[p.w].f>a[q.w].n-a[q.w].f){
				ans+=a[q.w].n;
				a[p.w].f+=a[q.w].n;
				q.w--;
				p.m+=a[q.w].n;
			}else{
				ans+=a[p.w].n;
				a[q.w].f+=a[p.w].n;
				p.w--;
				q.m+=a[p.w].n;				
			}
		}else{
			if(a[p.w].n-a[p.w].f==a[q.w].n-a[q.w].f){
				p.w++;
				q.w--;
				if(a[p.w].n-a[p.w].f<=p.m){
					p.m-=a[p.w].n-a[p.w].f;
					p.w++;
				}
				if(a[q.w].n-a[q.w].f<=q.m){
					q.m-=a[q.w].n-a[q.w].f;
					q.w++;
				}
			}else if(a[p.w].n-a[p.w].f>a[q.w].n-a[q.w].f){
				q.w--;
				p.m+=a[q.w].n;
			}else{
				p.w--;
				q.m+=a[p.w].n;				
			}			
		}
	}
	cout<<ans;
}
