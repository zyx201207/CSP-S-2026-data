#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long i=0,j=sum,i2=1,j2=n;
	while(i<j&&i2<j2){
		if(a[i2]>a[j2]){
			if(c[i2]!=c[j2]){
				ans+=a[j2];
			}
			i+=a[j2],j-=a[j2];
			a[i2]-=a[j2];
			a[j2]=0;
			j2--;
		}
		else if(a[i2]<a[j2]){
			if(c[i2]!=c[j2]){
				ans+=a[i2];				
			}
			i+=a[i2],j-=a[i2];
			a[j2]-=a[i2];
			a[i2]=0;
			i2++;
		}
		else{
			if(c[i2]!=c[j2]){
				ans+=a[i2];				
			}
			i+=a[i2],j-=a[i2];
			a[i2]=0;
			a[j2]=0;
			i2++;
			j2--;
		}
//		cout<<"i:"<<i<<" i2:"<<i2<<" j:"<<j<<" j2:"<<j2<<'\n';
	}
	cout<<ans;
	return 0;
}
