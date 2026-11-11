#include<bits/stdc++.h>
using namespace std;

long long n,m;


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	long long a[n];
	long long ans=0,tm=0,tans,temp=0,b=0,temp1=0;


	for(int i=0;i<n;i++){
      cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		tans=0;
		for(long long j=1;j<=i;j++){
				temp=a[i]-a[i-j];
				tm=tm-temp;
				tans++;
				if(tm==0){
					tans+=1;
					break;
				}
				if(tm<0){
					break;
				}
			}
			if(tans>=ans) ans=tans;
			tm=m;
			//cout<<tans<<endl;
		}
		//if(ans<3000) ans+=1;



	cout<<ans;
	return 0;
}
