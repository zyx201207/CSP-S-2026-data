#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=2*1e5+10,INF=1e9;
ll n=0,ans=0,sum=0;
pair<ll,char> arr[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].first>>arr[i].second;
		sum+=arr[i].first;
	}
	
	ll l=1,i=1,j=n,r=sum;
	while(i<j && l<=r){
		if(arr[i].first==arr[j].first && arr[i].second==arr[j].second){
			l+=arr[i].first;
			r-=arr[j].first;
			i++;
			j--;
		}
		else if(arr[i].second==arr[j].second && arr[i].first!=arr[j].first){
			if(arr[i].first<arr[j].first){
				l+=arr[i].first;
				r-=arr[i].first;
				arr[j].first-=arr[i].first;
				i++;
			}
			else{
				r-=arr[j].first;
				l+=arr[j].first;
				arr[i].first-=arr[j].first;
				j--;
			}
		}
		else if(arr[i].second!=arr[j].second && arr[i].first==arr[j].first){
			l+=arr[i].first;
			r-=arr[j].first;
			ans+=arr[i].first;
			i++;
			j--;
		}
		else{
			if(arr[i].first<arr[j].first){
				l+=arr[i].first;
				r-=arr[i].first;
				ans+=arr[i].first;
				arr[j].first-=arr[i].first;
				i++;
			}
			else{
				l+=arr[j].first;
				r-=arr[j].first;
				ans+=arr[j].first;
				arr[i].first-=arr[j].first;
				j--;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
