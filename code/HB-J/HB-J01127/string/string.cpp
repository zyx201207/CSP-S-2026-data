#include<bits/stdc++.h>
using namespace std;
long long n,sum=1,c[200005],pre[200005],l,r,l1,r1,t,c1,c2,ans;
char z[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cin>>z[i];
		c[i]+=c[i-1];
	}c[n];
	r=c[n],r1=n;
	l=1,l1=1;
	while(l<=(c[n]+1)/2 &&r>=(c[n]+1)/2){
		t=0;
		if(l1!=r1){	
			c1=c[l1],c2=c[r1-1];
			t=min(c[l1],c[r1]);
			l+=t,r-=t;
			c[l1]-=t;
			c[r1]-=t;
		}else{
			break;
		}
		if(z[l1]!=z[r1]){	
			ans+=t;
		}if(l>c1){
			l1++;
		}if(r<c2){
			r1--;
		}
	}cout<<ans<<"\n";
}
