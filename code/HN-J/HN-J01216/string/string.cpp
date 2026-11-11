#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans,cnt;
char c[1000005];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n/2;i++){
		if(f==1){
			if(c[ans]!=c[n-i-1]){
				if(a[ans]>a[n-1-i]){
					cnt+=a[n-i-1];
					a[ans]=a[ans]-a[n-i-1];
					a[n-i-1]=0;
					f=1;
				}
				else if(a[ans]==a[n-i-1]){
					cnt+=a[ans];
					a[ans]=0;
					a[n-i-1]=0;
					f=0;
				}
				else{
					cnt+=a[ans];
					a[n-i-1]=a[n-i-1]-a[ans];
					a[ans]=0;
					f=0;
				}			
			}
		}
		if(c[i]!=c[n-i-1]){
			if(a[i]>a[n-i-1]){
				cnt+=a[n-i-1];
				a[i]=a[i]-a[n-i-1];
				a[n-i-1]=0;
				f=1;
				ans=i;
			}
			else if(a[i]==a[n-i-1]){
				cnt+=a[i];
				a[i]=0;
				a[n-i-1]=0;
				f=0;
			}
			else{
				cnt+=a[i];
				a[n-i-1]=a[n-i-1]-a[i];
				f=1;
				a[i]=0;
				ans=n-i-1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
