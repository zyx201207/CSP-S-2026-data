#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200100],head=0,tail=0,s=0,start=0,z=1,y=0,ans=0;
char b[200200],o,p;
ll l[200200],r[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	s/=2;
	ll v=0;
	for(int i=1;i<=n;i++){
		v+=a[i];
		if(v>=s) break;
	}
	v-=s;
	while(start<=s){
		if(head==0){
			head=a[z];
			o=b[z];
			z++;
		}
		if(tail==0){
			tail=a[y];
			p=b[y];
			y--;
		}
		int mx=max(head,tail),mi=min(head,tail);
		
		if(o!=p){
			if(start+mi>s){
				ans+=v;
		}else{
			ans+=mi;
		}
		}
		head-=mi;
		tail-=mi;
		start+=mi;
	}
	cout<<ans;
	return 0;
}