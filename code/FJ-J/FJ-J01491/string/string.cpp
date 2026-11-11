#include<bits/stdc++.h>
using namespace std;
struct s{
	long long s;
	char v;
}a[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		scanf("%lld %c",&a[i].s,&a[i].v);
	}
	long long i=1,j=n;
	while(i<j){
		if(a[i].s<a[j].s){
			if(a[i].v!=a[j].v){
				ans+=a[i].s;
			}
			a[j].s-=a[i].s;
			i++;
		}else if(a[i].s==a[j].s){
			if(a[i].v!=a[j].v){
				ans+=a[i].s;
			}
			i++;j--;
		}else{
			int f=0;
			while(f==0){
				if(a[i].s>a[j].s){
					if(a[i].v!=a[j].v) ans+=a[j].s;
					a[i].s-=a[j].s;
					j--;
				}else if(a[i].s==a[j].s){
					if(a[i].v!=a[j].v) ans+=a[i].s;
					a[i].s-=a[j].s;
					i++;j--;
					f=1;
				}else{
					if(a[i].v!=a[j].v) ans+=a[i].s;
					a[j].s-=a[i].s;
					i++;
					f=1;
				}
			}
		}
	}
	cout<<ans;
 	return 0;
}
