#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
}a[200005];
long long t,ans,ln,len;
queue<node>q1,q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].x>>a[i].c;
		ln+=a[i].x;
	}
	len=ln/2;
	for(int i=1;i<=t;i++){
		if(len==0)break;
		if(len>=a[i].x){
			q1.push(a[i]);
			len-=a[i].x;
		}else if(len<a[i].x){
			q1.push({len,a[i].c});
			len=0;
		}
	}
	len=ln/2;
	for(int i=t;i>=1;i--){
		if(len==0)break;
		if(len>=a[i].x){
			q2.push(a[i]);
			len-=a[i].x;
		}else if(len<a[i].x){
			q2.push({len,a[i].c});
			len=0;
		}
	}
	len=ln/2;
	for(int i=1;i<=len;i++){
		node h=q1.front(),h2=q2.front();
		if(h.x==h2.x){
			if(h.c!=h2.c)ans+=h.x;
			q1.pop();
			q2.pop();
		}else if(h.x>h2.x){
			if(h.c!=h2.c){
				ans+=h2.x;
			}
			h.x-=h2.x;
			q2.pop();
		}else if(h.x<h2.x){
			if(h.c!=h2.c){
				ans+=h.x;
			}
			h2.x-=h.x;
			q1.pop();
		}
	}
	cout<<ans;
	return 0;
}
