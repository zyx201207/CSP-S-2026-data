#include<bits/stdc++.h>
using namespace std;
long long n,cs[200005],sum=0;
char zm[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>cs[i]>>zm[i];
	long long l=1,r=n;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		//cout<<1;
		if(zm[l]!=zm[r]){
			if(cs[l]>cs[r]){
				cs[l]-=cs[r];
				sum+=cs[r];
				r--;
			}
			else if(cs[l]==cs[r]){
				l++;
				sum+=cs[r];
				r--;
			}
			else {
				cs[r]-=cs[l];
				sum+=cs[l];
				l++;
			}
		}
		else {
			//cout<<l<<" "<<r<<endl;
			if(cs[l]>cs[r]){
				cs[l]-=cs[r];
				r--;
			}
			else if(cs[l]==cs[r]){
				l++;
				r--;
			}
			else {
				cs[r]-=cs[l];
				l++;
			}
		}
		if(cs[l]==0)l++;
		if(cs[r]==0)r--;
	}
	cout<<sum;
	return 0;
}
