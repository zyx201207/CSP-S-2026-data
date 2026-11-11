#include<bits/stdc++.h>
using namespace std;
pair<long long,char> a[200000];
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int l=0,r=n-1;
	while(l!=r){
		if(a[l].second==a[r].second){
			if(a[l].first==a[r].first)
			l++,r--;
			else{
				if(a[l].first>a[r].first){
					a[l].first-=a[r].first;
					r--;
				}else{
					a[r].first-=a[l].first;
					l++;
				}
			}
		}else{
			if(a[l].first==a[r].first){
				ans+=a[l].first;
				l++,r--;	
			}
			else{
				if(a[l].first>a[r].first){
					ans+=a[r].first;
					a[l].first-=a[r].first;
					r--;
				}else{
					ans+=a[l].first;
					a[r].first-=a[l].first;
					l++;
				}		
			}
		
		}
	}
			cout<<ans;
	
	return 0;
}
