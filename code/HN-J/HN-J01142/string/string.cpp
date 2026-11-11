#include<bits/stdc++.h>
using namespace std;
struct info{
	long long sz;
	char zf;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].sz>>a[i].zf;
	}
	int j=n-1;
	for(long long i=0;i<n;i++){
		long long zs=a[i].sz;
		if(i>=j)break;
		while(zs>0){
			if(a[i].zf!=a[j].zf){
				if(zs>=a[j].sz){
				zs-=a[j].sz;
				ans+=a[j].sz;
				j--;
			    }else{
				    ans+=zs;
				    zs=0;
			    }
			}else break;
		}
	}
	cout<<ans;
	return 0;
}

