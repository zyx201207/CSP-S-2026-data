#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,mid,qh,hh,cq,ch,l,ans;
struct Node{
	long long d;
	char c;
}a[N],q[N],h[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].c;
		l+=a[i].d; 
	}  
	mid=(l+1)/2;
	int i;
	for(i=1;qh<mid;qh+=a[i].d,i++){
		if(i!=1&&a[i].c==q[cq].c){
			q[cq].d+=a[i].d;
		}else{
			q[++cq].d=a[i].d;
			q[cq].c=a[i].c;
		}
	}
	for(int j=n;j>=i;j--){
		if(j!=n&&a[j].c==h[ch].c){
			h[ch].d+=a[j].d;
		}else{
			h[++ch].d=a[j].d;
			h[ch].c=a[j].c;
		}
	}
	if(l%2){
		if(qh==mid){
			q[cq].d--;
		}else{
			q[cq].d-=(qh-mid+1);
			if(q[cq].c==h[ch].c){
				h[ch].d+=(qh-mid);
			}else{
				h[++ch].d=(qh-mid);
				h[ch].c=q[cq].c;
			}
		}
	}else if(qh>mid){
			q[cq].d-=(qh-mid);
			if(q[cq].c==h[ch].c){
				h[ch].d+=(qh-mid);
			}else{
				h[++ch].d=(qh-mid);
				h[ch].c=q[cq].c;
			}
	}
	int j;
	for(i=1,j=1;i<=cq&&j<=ch;i++,j++){
		if(q[i].d==h[j].d){
			if(q[i].c!=h[j].c){
				ans+=q[i].d;
			}
		}else{
			if(q[i].d>h[j].d){
				if(q[i].c!=h[j].c){
					ans+=h[j].d;
					q[i].d-=h[j].d;
					i--;
				}
			}else{
				if(q[i].c!=h[j].c){
					ans+=q[i].d;
					h[j].d-=q[i].d;
					j--;
				}
			}
		} 
	}
	cout<<ans;
	return 0;
}
