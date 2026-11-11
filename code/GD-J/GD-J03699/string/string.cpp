#include<iostream>
#include<queue>
#include<stack>
using namespace std;
long long n,a[200005],ji=0,lei=0,mid=0,jl,lei1=0,lei2=0,ans=0,len1=0;
char r[200005],z1,z2,rr[2];
struct ll{
	long long len;
	char dat;
};
deque<ll>q1;
stack<ll>q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>r[i];
		ji+=a[i];
	}
	if(ji%2==0){
		mid=ji/2;
		for(int i=1;i<=n;i++){
			lei+=a[i];
			if(lei==mid){
				jl=i+1;
				q1.push_back({a[i],r[i]});
				break;
			}
			if(lei>mid){
				q1.push_back({a[i]-lei+mid,r[i]});
				q2.push({lei-mid,r[i]});
				jl=i+1;
				break;
			}
			q1.push_back({a[i],r[i]});
		}
		for(int i=jl;i<=n;i++) q2.push({a[i],r[i]});
		while(!q2.empty()){
			lei2+=q2.top().len;		
			z2=q2.top().dat;
			q2.pop();
			while(lei1<lei2&&!q1.empty()){
				lei1+=q1.front().len;
				len1=q1.front().len;
				z1=q1.front().dat;
				q1.pop_front();
				if(lei1>lei2){				
					q1.push_front({lei1-lei2,z1});					
					if(z1!=z2){
						ans+=(len1-lei1+lei2);
					}
					lei1=lei2;
				}
				else{
					if(z1!=z2){
						ans+=len1;
					}
				}
			}
		}
		cout<<ans;
	}
	else{
		mid=ji/2;
		for(int i=1;i<=n;i++){
			lei+=a[i];
			if(lei==mid){
				jl=i+1;
				q1.push_back({a[i],r[i]});
				break;
			}
			if(lei==mid+1){
				jl=i+1;
				q1.push_back({a[i]-1,r[i]});
				break;
			}
			if(lei>mid){
				q1.push_back({a[i]-lei+mid,r[i]});
				q2.push({lei-mid-1,r[i]});
				jl=i+1;
				break;
			}
			q1.push_back({a[i],r[i]});
		}
		for(int i=jl;i<=n;i++) q2.push({a[i],r[i]});
		while(!q2.empty()){
			lei2+=q2.top().len;			
			z2=q2.top().dat;
			q2.pop();
			while(lei1<lei2&&!q1.empty()){				
				lei1+=q1.front().len;
				len1=q1.front().len;
				z1=q1.front().dat;
				q1.pop_front();		
				if(lei1>lei2){					
					q1.push_front({lei1-lei2,z1});
					if(z1!=z2){
						ans+=(len1-lei1+lei2);
					}
					lei1=lei2;
				}
				else{
					if(z1!=z2){
						ans+=len1;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
