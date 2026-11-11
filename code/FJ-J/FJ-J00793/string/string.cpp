#include<bits/stdc++.h>
using namespace std;
long long a[3000],d[3000];
char c[3000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d[i]=a[i]+d[i-1];
	}
	long long mid=(d[n]+1)/2;
	long long i1=1,j1=1,i2=d[n],j2=n;
	long long ans=0;
	while(mid<i2){
		if(d[j1]>d[n]-d[j2-1]){
			if(c[j1]!=c[j2]){
				ans+=i2-d[j2-1];
				if(i2-(i2-d[j2-1])<=mid){
					ans-=i2-mid; 
					break;
				}
			}
			i1+=(i2-d[j2-1]),i2-=(i2-d[j2-1]),j2--;
		}else if(d[j1]<d[n]-d[j2-1]){
			if(c[j1]!=c[j2]){
				ans+=d[j1]-i1+1;
				if(i2-(d[j1]-i1+1)<=mid){
					ans-=i2-mid; 
					break;
				}
			}
			i2-=(d[j1]-i1+1),i1+=(d[j1]-i1+1),j1++;
		}else{
			if(c[j1]!=c[j2]){
				ans+=d[j1]-i1+1;
				if(i2-(d[j1]-i1+1)<=mid){
					ans-=i2-mid; 
					break;
				}
			}
			i2-=(d[j1]-i1+1),i1+=(d[j1]-i1+1),j1++,j2++;
		}
	}
	cout<<ans;
	return 0;
}
