#include<bits/stdc++.h>
using namespace std;
long long l,r,w,q;
long long n,s=0,t;
long long ans;
struct node{
	long long num;
	char k;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long ss;
		char sss;
		cin>>ss>>sss;
		if(a[s].k==sss){
			a[s].num+=ss;
		}
		else{
			a[++s].num=ss;
			a[s].k=sss;
		}
		r+=ss;
	}
	t=r;
	ans=r/2;
	l=0;
	w=0;
	q=s+1;
	while(w<q){
		if(l<=t-r){
			l+=a[++w].num;
			if(a[w].k==a[q].k){
				if(q==w){
					ans-=min(l-(t+1)/2,t/2-r);	
				}
				//cout<<1<<"\n";
				else if(l<=t-r &&w!=q){
					ans-=a[w].num;
				}
				else{
					ans-=t-r-(l-a[w].num);
				}
			}
		}
		else{
			r-=a[--q].num;
			if(a[q].k==a[w].k){
				if(q==w){
					//cout<<1;
					ans-=min(t/2-r,l-(t+1)/2);
				}
				else if(t-r<=l){
					//cout<<1;
					ans-=a[q].num;
				}
				else{
					//cout<<2;
					ans-=l-(t-r-a[q].num);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
