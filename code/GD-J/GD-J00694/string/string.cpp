#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10,maxn2=1e5+10;
struct hss{
	int m;
	char c;
}a[maxn],b[maxn2],c1[maxn2],c[maxn2];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,sum1=0;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i].m);
		cin>>a[i].c; 
		sum+=a[i].m;
	}
	int e1=0,e2=0,i1=0,i2=0;
	bool f=false;
	if(sum%2==0){
		for(int i=0;i<n;i++){
			sum1+=a[i].m;
			if(sum1<=sum/2){
				b[e1].m=a[i].m;
				b[e1++].c=a[i].c;
			}
			else{
				if(f){
					c1[e2].m=a[i].m;
					c1[e2++].c=a[i].c;
				}
				else if(sum1-a[i].m==sum/2){
					c1[e2].m=a[i].m;
					c1[e2++].c=a[i].c;
				}
				else{
					b[e1].m=(sum/2)-(sum1-a[i].m);
					b[e1++].c=a[i].c;
					c1[e2].m=sum1-(sum/2);
					c1[e2++].c=a[i].c;
				}
				f=true;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			sum1+=a[i].m;
			if(sum1<=sum/2){
				b[e1].m=a[i].m;
				b[e1++].c=a[i].c;
			}
			else{
				if(f){
					c1[e2].m=a[i].m;
					c1[e2++].c=a[i].c;
				}
				else if(sum1-a[i].m==sum/2){
					c1[e2].m=a[i].m-1;
					c1[e2++].c=a[i].c;
				}
				else{
					b[e1].m=(sum/2)-(sum1-a[i].m);
					b[e1++].c=a[i].c;
					c1[e2].m=sum1-(sum/2)-1;
					c1[e2++].c=a[i].c;
				}
				f=true;
			}
		}
	}
	for(int i=0;i<e2;i++){
		c[e2-i-1].m=c1[i].m;
		c[e2-i-1].c=c1[i].c;
	}
//	for(int i=0;i<e1;i++){
//		cout<<b[i].m<<" "<<b[i].c<<endl;
//	}
//	cout<<endl;
//	for(int i=0;i<e2;i++){
//		cout<<c[i].m<<" "<<c[i].c<<endl;
//	}
	int ans=0;
	while(1){
		if(i1==e1&&i2==e2){
			break;
		}
		if(b[i1].m==c[i2].m){
			if(b[i1].c==c[i2].c){
				i1++;
				i2++;
			}
			else{
				ans+=b[i1].m;
				i1++;
				i2++;
			}
		}
		if(b[i1].m>c[i2].m){
			if(b[i1].c==c[i2].c){
				b[i1].m-=c[i2].m;
				i2++;
			}
			else{
				ans+=b[i1].m-c[i2].m;
				b[i1].m-=c[i2].m;
				i2++;
			}
		}
		if(b[i1].m<c[i2].m){
			if(b[i1].c==c[i2].c){
				c[i2].m-=b[i1].m;
				i1++;
			}
			else{
				ans+=c[i2].m-b[i1].m;
				c[i2].m-=b[i1].m;
				i1++;
			}
		}
	} 
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
--------·Ö½çÏß--------
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

*/
