#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct stu{
	int x;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
	}
	long long ans=0;
	long long cnt=0;
	for(int i=1,j=n;i<j;i++){
		if(a[i].s!=a[j].s){
			if(a[i].x>a[j].x){
				int cnt1=cnt+a[i].x;
				while(1){
					if(cnt+a[j].x>=cnt1){
						if(a[i].s==a[j].s){
							continue;
						}
						else{
							ans+=cnt1-cnt;
						}
						cnt=cnt1;
						break;
					}
					else{
						cnt+=a[j].x;
						if(a[i].s==a[j].s){
							continue;
						}
						else{
							ans+=a[j].x;
						}	
					}
					j--;
				}
			}
			else{
				ans+=a[i].x;
				cnt+=a[i].x;
			}
		}
	}
	long long ans0=0;
	long long cnt0=0;
	for(int i=n,j=1;i>j;i--){
		if(a[i].s!=a[j].s){
			if(a[i].x>a[j].x){
				int cnt1=cnt0+a[i].x;
				while(1){
					if(cnt0+a[j].x>=cnt1){
						if(a[i].s==a[j].s){
							continue;
						}
						else{
							ans0+=cnt1-cnt0;
						}
						cnt0=cnt1;
						break;
					}
					else{
						cnt0+=a[j].x;
						if(a[i].s==a[j].s){
							continue;
						}
						else{
							ans0+=a[j].x;
						}	
					}
					j++;
				}
			}
			else{
				ans0+=a[i].x;
				cnt0+=a[i].x;
			}
		}
	}
	long long minn=min(ans0,ans);
	cout<<minn;
	return 0;
}
