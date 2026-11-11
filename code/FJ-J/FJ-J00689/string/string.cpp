#include<bits/stdc++.h>
using namespace std;
long long sum,ss;
int n,k=0,x;
char c[200005];
struct S{
	long long l;
	char r;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a>>c[i];
		if(c[i]==c[i-1]){
			b[k].l+=a;
		}else {
			k++;
			b[k].l=a;
			b[k].r=c[i];
		}ss+=a;
	}int j=k,z=0;;
	char p=b[1].r;
	for(int i=1;i<=k/2;i++){
		if(b[i].r!=b[j].r){
			sum+=min(b[i].l,b[j].l);
			z=abs(b[i].l-b[j].l);
			if(b[i].l>b[j].l){
				if(b[i].r!=b[j-1].r)sum+=z;
				if(b[j-1].l>=z)b[j-1].l-=z;
					else{
						j--;
						b[j-1].l-=z-b[j].l;
					}
			}else if(b[i].l<b[j].l){
				if(b[j].r!=b[i+1].r)
					sum+=z;
					if(b[i+1].l>=z)b[i+1].l-=z;
					else{
						i++;
						b[i+1].l-=z-b[i].l;
					}
			}
		}else {
			if(b[i].l>b[j].l){
				if(b[i].r!=b[j-1].r)sum+=z;
				if(b[j-1].l>=z)b[j-1].l-=z;
					else{
						j--;
						b[j-1].l-=z-b[j].l;
					}
			}else if(b[i].l<b[j].l){
				if(b[j].r!=b[i+1].r)
					sum+=z;
					if(b[i+1].l>=z)b[i+1].l-=z;
					else{
						i++;
						b[i+1].l-=z-b[i].l;
					}
			}
		}j--;
	}cout<<sum;
}
