#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,w,sum,top,ans;
char v;
struct data{
	ll a;
	char c;
}q[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(ll i=1;i<=n;i++){
		cin>>w>>v;
		if(q[top].c==v)q[top].a+=w;
		else {
			top++;
			q[top].c=v;
			q[top].a=w;
		}
	}
	
//	for(ll i=1;i<=top;i++){
//		cout<<q[i].a<<" "<<q[i].c<<"\n";
//	}
	
	if(top==1){
		cout<<0;
		return 0;
	}
	
	for(ll l=1,r=top;l<r;){
		if(q[l].c==q[r].c){
			if(q[l].a<q[r].a){
				q[r].a=q[r].a-q[l].a;
				l++;
			}else if(q[l].a>q[r].a){
				q[l].a=q[l].a-q[r].a;
				r--;
			}else l++,r--;
		}
		else {
			if(q[l].a<q[r].a){
				ans+=q[l].a;
				q[r].a=q[r].a-q[l].a;
				l++;
			}else if(q[l].a>q[r].a){
				ans+=q[r].a;
				q[l].a=q[l].a-q[r].a;
				r--;
			}else {
				ans+=q[r].a;
				l++,r--;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
} 
/*
3
2 a
5 b
4 a
*/
