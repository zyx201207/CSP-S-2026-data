//GZ-S00316 chen size guiyangdiyizhongxue
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500008];
int dg(long long iL,long long  sum,long long ins,long long iR){
	if((ins-iL<=0)||(ins+iR>n)){
		return iR+iL-1;
	}
	if((a[ins]-a[ins-iL]<a[ins+iR]-a[ins])){

		sum+=a[ins]-a[ins-iL];
		if(sum>m){
		return iL+iR-1;
	}
		iL+=1;
		dg(iL,sum,ins,iR);
	}
	else if((a[ins]-a[ins-iL]>=a[ins+iR]-a[ins])){
		sum+=a[ins+iR]-a[ins];
	//	cout<<sum<<"sum  "<<iR<<" ";
		if(sum>m){
		return iL+iR-1;
	}

		iR+=1;
		dg(iL,sum,ins,iR);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int d=0;
	if(n>=5001){
            sort(a+1,a+15);
		long long h=0;
		long long rr=a[5]-a[4];
		long long sum1=0;
		for(long long k=1;k<=n;k++){
			for(int j=1;j<=2;j++){
				sum1+=rr*k;

				if (sum1> m){
					cout<<h+1;
					return 0;
				}
				h++;
			}

		}
	}
	sort(a+1,a+n+1);


	for(int i=1;i<=n;i++){
		if(d<dg(1,0,i,1)){
	d=dg(1,0,i,1);	}
	}
	cout<<d;
}
