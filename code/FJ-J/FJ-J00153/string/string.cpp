#include<bits/stdc++.h>
using namespace std;
struct words{
	long long m;
	char c;
}a[200044];
long long n,sum,ans,la,ra,lb,rb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		sum+=a[i].m;
		if((a[i].c==a[i-1].c)&&(i!=1)){
			a[i-1].m+=a[i].m;
			n--;
			i--;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	la=1;ra=sum;lb=1;rb=n;ans=0;
	while(1){
		if(a[lb].m>a[rb].m){
			la+=a[rb].m;
			ra-=a[rb].m;
			a[lb].m-=a[rb].m;
			if(a[lb].c!=a[rb].c){
				ans+=a[rb].m;
			}
			rb--;
		}else if(a[lb].m<a[rb].m){
			la+=a[lb].m;
			ra-=a[lb].m;
			a[rb].m-=a[lb].m;
			if(a[lb].c!=a[rb].c){
				ans+=a[lb].m;
			}
			lb++;
		}else{
			la+=a[lb].m;
			ra-=a[lb].m;
			a[rb].m-=a[lb].m;
			a[lb].m-=a[rb].m;
			if(a[lb].c!=a[rb].c){
				ans+=a[lb].m;
			}
			lb++;
			rb--;
		}
		if(ra<sum/2||la>sum/2){
			break;
		}
	}
	cout<<ans;
	return 0;
}
