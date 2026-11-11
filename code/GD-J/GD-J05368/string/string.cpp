#include<bits/stdc++.h>
using namespace std;

int n,ans,len,mid,ip;

struct c{
	int m;
	char b;
	int h;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].b;
		len+=a[i].m;
		a[i].h=len;
	}
	
	mid=len/2+1;
	for(int i=1;i<=n;i++){
		if(mid<=a[i].h){
			ip=i;
			break;
		}
	}
	
	for(int i=ip;i<=n;i++){
		if(a[i].b != a[ip-i+1].b) ans+=a[i].h-mid-ans;
	}
	cout<<ans<<endl;
	return 0;
} 
