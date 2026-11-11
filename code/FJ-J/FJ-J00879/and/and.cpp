#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,m;
long long arr[N];
long long a2[N][40];
long long cnt2[40];
long long x;
long long ci2[40];
set<long long>  id;
queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ci2[0]=1;
	for(int i=1;i<=31;i++){
		ci2[i]=ci2[i-1]*2;
	}
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		id.insert(i);
		x=arr[i];
		long long cnt=0;
		while(x){
			if(x&1){
				a2[i][cnt]=1;
				cnt2[cnt]++;
			}
			cnt++;
			x>>=1;
		}
	}
	long long beg=32;
	long long flag=true;
	long long ans=0;
	while(beg-1>=0){
		flag=true;
		for(int i=beg-1;i>=0;i--){
			if(cnt2[i]>=m){
				ans+=ci2[i];
				flag=false;
				beg=i;
				break;
			}
		}
		if(flag){
			break;
		}
		for(auto a:id){
			if(a2[a][beg]==0){
				for(int j=0;j<=31;j++){
					if(a2[a][j]==1){
						cnt2[j]--;
					}
				}
				q.push(a);
			}
		}
		long long has=0;
		while(!q.empty()){
			long long a=q.front();
			q.pop();
			id.erase(a);
			has++;
		}
	}
	cout<<ans;
	return 0;
} 
