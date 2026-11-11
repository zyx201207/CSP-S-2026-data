#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
unsigned long long n,a[N];
char c[N];
unsigned long long sum;
signed main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   cin>>n;
	int v=0;
 	int x;
  	char y;
  	for(int i=1;i<=n;i++){
   	cin>>x>>y;
   	sum+=x;
   	if(y==c[v]){
	   a[v]+=x;
	   }else{
	   	v++;
	   	c[v]=y;
	   	a[v]=x;
	   }
  	 }
  	int yu=sum%2;
 	int cha,mi;
 	sum/=2;
 	unsigned long long num=0,ans=0;
  	for(int i=1;i<=v;i++){
   	num+=a[i];
   	if(num>=sum+yu){
   		mi=i;
   		break;
	   }
  	 }
//  	 cout<<sum<<" "<<num<<endl;
//  	 cout<<mi<<endl;
   	int i=1,j=v;
   	while(i<=mi&&j>=mi){
//   		cout<<i<<":"<<c[i]<<","<<j<<":"<<c[j]<<endl;
		if(c[i]!=c[j]){
				if(a[i]>a[j]){
//					cout<<i<<","<<j<<endl;
					ans+=a[j];
					a[i]-=a[j];
//					cout<<1<<" "<<a[j]<<endl;
					j--;
				}else{
//					cout<<i<<","<<j<<endl;
					ans+=a[i];
					a[j]-=a[i];
//					cout<<2<<" "<<a[i]<<endl;
					i++;
				}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
   	}
   	cout<<ans;
	return 0;
}

