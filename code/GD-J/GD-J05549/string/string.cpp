#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	long long ri=n,las=0,ans=0; 
	for(int i=1;i<=n;i++){
		long long l=a[i].s;
		while(l>0){
			l-=a[ri].s-las;
			if(l<0){
				if(a[ri].c!=a[i].c) ans+=a[ri].s+l;
				las=0-l;
			} 
			else if(l==0){
				if(a[ri].c!=a[i].c) ans+=a[i].s;
				ri--;
				las=0;
			}
			else if(l>0){
				if(a[ri].c!=a[i].c) ans+=a[ri].s-l;
				ri--;
				las=0;
			}
		}
		if(ri==i) break;
	}
	
	long long ansl=0,li=1;
	las=0;
	for(int i=n;i>=1;i--){
		long long r=a[i].s;
		while(r>0){
			r-=a[li].s-las;
			if(r<0){
				if(a[li].c!=a[i].c) ansl+=a[li].s+r;
				las=0-r;
			} 
			else if(r==0){
				if(a[li].c!=a[i].c) ansl+=a[i].s;
				li++;
				las=0;
			}
			else{
				if(a[li].c!=a[i].c) ansl+=a[li].s-r;
				li++;
				las=0;
			}
		}
		if(li==i) break;
	}
	cout<<min(ans,ansl);
}
