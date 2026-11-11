#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s;
	char w;
}ls[200005],rs[200005];
long long sum,t,k,ans;
int n,a[200005],l,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	t=sum/2;
	for(int i=1;i<=n;i++){
		k=i;
		if(t==0){
			break;
		} 
		if(a[i]<=t){
			t-=a[i];
			ls[++l].s=a[i];
			ls[l].w=c[i];
		}else{
			ls[++l].s=t;
			ls[l].w=c[i];
			a[i]-=t;
			break;
		}
	}
	if(sum%2==1){
		a[k]--;
	}
	for(int i=k;i<=n;i++){
		rs[++r].s=a[i];
		rs[r].w=c[i];
	}
	for(int i=1;i<=l;i++){
		while(ls[i].s>0){ 
			if(ls[i].s>=rs[r].s){
				if(ls[i].w!=rs[r].w){
					ans+=(rs[r].s);
				}
				ls[i].s-=rs[r].s;
				r--;
			}else{
				if(ls[i].w!=rs[r].w){
					ans+=(ls[i].s);
				}
				rs[r].s-=ls[i].s;
				ls[i].s=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
