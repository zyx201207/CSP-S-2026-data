#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long ans=0;
long long a[200005]={};
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
	}
	queue<pair<long long,char>> que,que2;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		if(a[i]+cnt>=sum/2){
			que.push({sum/2-cnt,c[i]});
			break;
		}else{
			que.push({a[i],c[i]});
			cnt+=a[i];
		}
	}
	cnt=0;
	for(long long i=n;i>=1;i--){
		if(a[i]+cnt>=sum/2){
			que2.push({sum/2-cnt,c[i]});
			break;
		}else{
			que2.push({a[i],c[i]});
			cnt+=a[i];
		}
	}
    pair<long long,char> top1,top2;
	top1.first=que.front().first;
	top1.second=que.front().second;
	que.pop();
	top2.first=que2.front().first;
	top2.second=que2.front().second;
	que2.pop();
	while(top1.first||top2.first){
		if(top1.second==top2.second){
			if(top1.first>=top2.first){
				top1.first-=top2.first;
				top2.first=0;
			}else{
				top2.first-=top1.first;
				top1.first=0;
			}
		}else{
			if(top1.first>=top2.first){
				top1.first-=top2.first;
				
				ans+=top2.first;top2.first=0;
			}else{
				top2.first-=top1.first;
				
				ans+=top1.first;top1.first=0;
			}
		}
		if(top1.first==0&&!que.empty()){
			top1=que.front();
			que.pop();
		}
		if(top2.first==0&&!que2.empty()){
			top2=que2.front();
			que2.pop();
		}
	//	cout<<top2.x<<top1.x;
	}
	cout<<ans;
	return 0;
}

