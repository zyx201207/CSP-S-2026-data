#include<bits/stdc++.h>
using namespace std;
long long n;
pair<long long,char> a[200005];
long long ans=0;
long long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a[i].first>>a[i].second;
    	sum+=a[i].first;
	}
	bool tf=(sum%2==0)?true:false; 
	long long i=1;
	long long j=n;
	while(1){
		long long minn=0;
		long long now=0;
		if(a[i].first<=a[j].first){
			minn=a[i].first;
			now=i;
		}
		else{
			minn=a[j].first;
			now=j;
		}
		if(a[i].second==a[j].second){
			if(now==j){
				j--;
				a[i].first-=minn;
				if(a[i].first==0){
					i++;
				}
			}
			if(now==i){
				i++;
				a[j].first-=minn;
				if(a[j].first==0){
					j--;
				}
			}
		}
		else{
			ans+=minn;
			if(now==j){
				j--;
				a[i].first-=minn;
				if(a[i].first==0){
					i++;
				}
			}
			if(now==i){
				i++;
				a[j].first-=minn;
				if(a[j].first==0){
					j--;
				}
			}
		}
		sum-=2*minn;
		if(tf==false&&sum==1){
			break;
		}
		if(sum<=0){
			break;
		}
	//	cout<<sum<<" "<<endl;
	}
	cout<<ans;
    return 0;
}
