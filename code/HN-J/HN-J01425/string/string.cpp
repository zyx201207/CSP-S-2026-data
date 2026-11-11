#include<bits/stdc++.h>
using namespace std;
long long n,l,gjz,ans;
struct node{
	long long m,x,te;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	scanf("%lld%s",&a[i].m,&a[i].x);
    	a[i].te=a[i].m;
	}
	for(int i=1,j=n;i<=j;){
		if(a[i].te<=a[j].te){
			gjz=a[i].te;
			a[j].te-=a[i].te;
			if(a[i].x!=a[j].x) ans+=gjz;
			i++;
		}else{
			gjz=a[j].te;
			a[i].te-=a[j].te;
			if(a[i].x!=a[j].x) ans+=gjz;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
