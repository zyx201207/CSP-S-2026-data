#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
};
long long mid,l,ans,now,le,r;
int n;
node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		l+=a[i].num;	
	}
	//cout<<l;
	
	le=1,r=n;
	
	if(l%2==0){
		mid=l/2;
		//cout<<mid<<" ";
		for(int i=1;i<=n;i++){
			now+=a[i].num;
			if(now+a[i+1].num>=mid){
				a[i+1].num=abs(now+a[i+1].num-mid-(mid-now));
				break;
			}
		}
	}else{
		mid=(l+1)/2;
		//cout<<mid<<" ";
		for(int i=1;i<=n;i++){
			now+=a[i].num;
			if(now+a[i+1].num>=mid){
				a[i+1].num--;
				l--;
				mid=l/2;//cout<<abs(now+a[i+1].num-mid-(mid-now))<<endl;
				a[i+1].num=abs(now+a[i+1].num-mid-(mid-now));
				
				break;
			}
		}
	}
	
	while(le<r){
		if(a[le].c!=a[r].c){
			if(a[le].num<a[r].num){//cout<<" ! "<<a[le].num<<endl;
				ans+=a[le].num;
				a[r].num-=a[le].num;
				le++;
				//cout<<ans<<endl;
			}else if(a[le].num>a[r].num){				//cout<<r<<" @ "<<a[r].num<<endl;
				ans+=a[r].num;
				a[le].num-=a[r].num;
				r--;
				//cout<<ans<<endl;
			}else{//cout<<ans<<" * le:"<<le<<" r:"<<r<<" "<<a[r].num<<endl;
				ans+=a[r].num;
				le++;
				r--;
				//cout<<ans<<endl;
			}
		}else{
			if(a[le].num<a[r].num){
				a[r].num-=a[le].num;
				le++;
			}else if(a[le].num>a[r].num){
				a[le].num-=a[r].num;
				r--;
			}else{
				le++;
				r--;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
