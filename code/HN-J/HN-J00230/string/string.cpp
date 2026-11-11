#include<bits/stdc++.h>
using namespace std;
struct zfc{
	long long len;
	char c;
} a[200010];
long long n,l,r;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%d",&n);
	r=n,l=1;
	for(int i=1;i<=n;i++) scanf("%d %c",&a[i].len,&a[i].c);	
	while(l<=r){
		if(a[l].len<a[r].len){
			a[r].len-=a[l].len;
			if(a[l].c!=a[r].c) ans+=a[l].len;
			l++;
		}
		else if(a[l].len>a[r].len){
			a[l].len-=a[r].len;
			if(a[l].c != a[r].c) ans+=a[r].len;
			r--;
		}
		else{
			if(a[l].c!=a[r].c) ans+=a[l].len;
			l++;
			r--;
		}
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
