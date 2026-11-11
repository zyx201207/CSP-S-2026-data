#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct num{
	long long nu,nnn;long long time=1;
};
long long n,m,ans,mnow,ansnow;
num a[500010];
bool cmp(num a,num b){
	return a.nu<b.nu;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int b1=0,b2=0;
	if(n==1){
		cout<<"1";return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].nu;
	}
	for(int i=0;i<n;i++){
		if(a[i].nu!=i+1){
			b1=1;break;
		}
	}
	if(b1==0){
		m=2*m;
		int l=0,r=n;
		while(b1!=1){
			ans=(l+r)/2;
			if(ans*(ans+1)<=m&&(ans+1)*(ans+2)>m){
				cout<<ans+1;return 0;
			}
			else if(ans*(ans+1)<=m){
				l=ans+1;
			}
			else{
				r=ans-1;
			}
		}
	}
	for(int i=0;i<n-2;i++){
		if(a[i].nu-a[i+1].nu==0||a[i].nu-a[i+1].nu!=a[i+1].nu-a[i+2].nu){
			b2=1;break;
		}
	}
	if(b2==0){
		int ll=a[1].nu-a[0].nu;
		m=2*m/ll;int l=0,r=n;
		while(b2!=1){
			ans=(l+r)/2;
			if(ans*(ans+1)<=m&&(ans+1)*(ans+2)>m){
				cout<<ans+1;return 0;
			}
			else if(ans*(ans+1)<=m){
				l=ans+1;
			}
			else{
				r=ans-1;
			}
		}
		return 0;
	}
	sort(a,a+n,cmp);long long k=0;
	for(int i=0;i<n;i++){
		a[k].nu=a[i].nu;a[k].nnn=i+1;
		//cout<<a[k].nu;
		if(a[i].nu==a[i+1].nu){
			a[k].time++;
			ans=max(ans,a[k].time);
		}
		else{
			k++;
		}
	}
//	for(int i=0;i<k;i++){
//		cout<<a[i].nnn<<" "<<a[i].nu<<" "<<a[i].time<<endl;
//	}
	if(n<500001){
		for(int i=0;i<k;i++){
			mnow=0;ansnow=0;
			for(int j=i+1;j<k;j++){
				mnow=mnow+(a[j].nu-a[j-1].nu)*(a[j].nnn-a[i].nnn+a[i].time-a[j].time);
				if(mnow>m){
					ansnow=a[j-1].nnn-a[i].nnn+a[i].time;
					break;
				}
				if(mnow==m){
					ansnow=a[j].nnn-a[i].nnn+a[i].time;
					break;
				}
			}
			if(mnow<m){
				ansnow=a[k-1].nnn-a[i].nnn+a[i].time;
			}
			//cout<<i<<" "<<ansnow<<" "<<mnow<<endl;
			ans=max(ans,ansnow);
		}
	}
	cout<<ans;
	return 0;
}
