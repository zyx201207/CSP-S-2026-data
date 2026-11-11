#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	deque<long long> dq;
	deque<long long> mx;
	long long need=0,ans=0;
	long long max1 = 1;
    for(int i=1;i<=n;i++){
    	while(!mx.empty()&&a[mx.back()]<a[i])mx.pop_back();
    	mx.push_back(i);
    	dq.push_back(i);
		if(a[i]>a[max1]){
			need+=(dq.size()-1)*(a[i]-a[max1]);
			max1 = i;
			while(need>m){
				need-=a[i]-a[dq.front()];
				dq.pop_front();
				//cout<<1<<endl;
			}
		}else if(a[i]<a[max1]){
			need+=a[max1]-a[i];
			while(need>m){
				if(dq.front()==max1){
					dq.pop_front();
					//cout<<2<<endl;
					mx.pop_front();
					need-=dq.size()*(a[max1]-a[mx.front()]);
					max1 = mx.front();
				}else{
					need-=a[max1]-a[dq.front()];
					dq.pop_front();
					//cout<<3<<endl;
				}
			}
		}
		max1 = mx.front();
		ans = max(ans,(long long)dq.size());
		/*for(int x:dq){
			cout<<a[x]<<' ';
		}
		cout<<endl;*/
	}
	cout<<ans;
	return 0;
}/*    	
    	long long new_max = mx.front();
				if(need>m){
			if(dq.front()==max){
				need-=dq.size()*
			}
		}*/
