#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+7;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}//cin
	long long l=1,r=n,cnt=0;
    while(l<r)
    {
    	if(c[l]!=c[r]){
    		if(a[l]>a[r]){
    			cnt+=a[r];
			//	cout<<"~1 "<<l<<" "<<r<<" "<<a[r]<<"\n";
    			a[l]-=a[r];
				a[r]=0;
    			
    			r-=1;
    			
			}
			else if(a[l]<a[r]){
				cnt+=a[l];
			//	cout<<"~2 "<<l<<" "<<r<<" "<<a[l]<<"\n";
				a[r]-=a[l];
				a[l]=0;
				
				l+=1;
			}
			else{
				cnt+=a[r];
			//	cout<<"~3 "<<l<<" "<<r<<" "<<a[r]<<"\n";
				a[r]=a[l]=0;
				l+=1,r-=1;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
    			a[r]=0;
    			r-=1;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l+=1;
			}
			else{
				a[r]=a[l]=0;
				l+=1,r-=1;
			}
		}
	}
	cout<<cnt;
	return 0;

}
