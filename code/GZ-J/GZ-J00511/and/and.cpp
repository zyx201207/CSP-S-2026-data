//GZ-J00511 张俊熙 兴义市弘毅中学
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,a[200005],mx,su,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}for(int i=1;i<=(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cnt++;
			}
		}if(cnt==m){
			for(int j=0;j<n;j++){
			    if(i&(1<<j)){
				   if(su==0){
				   	su=a[j];
				   }else su&=a[j];
			    }
		    }
		}mx=max(mx,su);
		su=0;cnt=0;
	}printf("%lld",mx);
	
	
	return 0;
}
