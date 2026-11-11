#include<bits/stdc++.h>
using namespace std;
long long n,s,l;
struct huiwen{
	long long x;
	char c;
}a[200010];
struct pre{
	long long q;
	char z;
}b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		s+=a[i].x;
	}
	if(s%2){
		long long p=s/2+1,k,ans=0;
		for(int i=1;i<=n;i++){
			if(l+a[i].x<p-1){
				l+=a[i].x;
				b[i].q=a[i].x;
				b[i].z=a[i].c;
			}else if(l+a[i].x>p-1){
				b[i].q=p-1-l;
				b[i].z=a[i].c;
			    (a[i].x)-=(p-1-l);
			    (a[i].x)--;
				l=p-1;
				if(a[i].x){
					k=i;
				}else{
					k=i+1;
				}
				break;
			}else{
				b[i].q=a[i].x;
				b[i].z=a[i].c;
				(a[i].x)=0;
				(a[i+1].x)--;
				if(a[i+1].x){
					k=i+1;
				}else{
					k=i+2;
				}
				break;
			}
		}
		int j=k;
		for(int i=1;i<=k;i++){
			if(b[i].q>a[j].x){
				if(b[i].z!=a[j].c){
					ans+=a[j].x;
					b[i].q-=a[j].x;
					a[j].x=0;
					j++;
					i--;
				}else{
				    b[i].q-=a[j].x;
					a[j].x=0;
					i--;
					j++;
				}
			}else if(b[i].q==a[j].x){
				if(b[i].z!=a[j].c){
					ans+=a[j].x;
					b[i].q=0;
					a[j].x=0;
					j++;
				}else{
					a[j].x=0;
					b[i].q=0;
					j++;
				}
			}else{
				if(b[i].z!=a[j].c){
					ans+=b[i].z;
					a[j].x-=b[i].q;
					b[i].q=0;
				}else{
				    a[j].x-=b[i].q;
					b[i].q=0;
				}
			}
		}
		cout<<ans;
	}else{
		long long p=s/2,k,ans=0;
		for(int i=1;i<=n;i++){
			if(l+a[i].x<p){
				l+=a[i].x;
				b[i].q=a[i].x;
				b[i].z=a[i].c;
			}else if(l+a[i].x>p){
				b[i].q=p-l;
				b[i].z=a[i].c;
			    (a[i].x)-=(p-l);
				k=i;
				break;
			}else{
				b[i].q=a[i].x;
				b[i].z=a[i].c;
				(a[i].x)=0;
				k=i+1;
				break;
			}
		}
		int j=k;
		for(int i=1;i<=k;i++){
			if(b[i].q>a[j].x){
				if(b[i].z!=a[j].c){
					ans+=a[j].x;
					b[i].q-=a[j].x;
					a[j].x=0;
					j++;
					i--;
				}else{
				    b[i].q-=a[j].x;
					a[j].x=0;
					i--;
					j++;
				}
			}else if(b[i].q==a[j].x){
				if(b[i].z!=a[j].c){
					ans+=a[j].x;
					b[i].q=0;
					a[j].x=0;
					j++;
				}else{
					a[j].x=0;
					b[i].q=0;
					j++;
				}
			}else{
				if(b[i].z!=a[j].c){
					ans+=b[i].z;
					a[j].x-=b[i].q;
					b[i].q=0;
				}else{
				    a[j].x-=b[i].q;
					b[i].q=0;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
