#include<bits/stdc++.h>
using namespace std;
long long qzh[500005],maxx,a[500005],n,m,now;
deque<long long>deq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	now=maxx=1;deq.push_back(1);
//	cout<<"现在“水晶杂烩”里面有"<<1<<"，加入了"<<a[deq.back()]<<",m为"<<m<<"，最大情况"<<maxx<<endl;
	for(int i=2;i<=n;i++){
		if(m-(now*(a[i]-a[i-1]))>=0){
	//		cout<<"加入"<<a[i]<<"花费" <<now*(a[i]-a[i-1])<<endl; 
			m-=(now*(a[i]-a[i-1]));
			now++;maxx=max(maxx,now);
			deq.push_back(i);
		}else{
			while(m-(now*(a[i]-a[i-1]))<0) {
		//		cout<<"踢出"<<a[deq.front()]<<"并且为m加回其消耗的" << a[deq.back()]-a[deq.front()];
				m+=a[deq.back()]-a[deq.front()];//cout<<"m:"<<m- (a[deq.back()]-a[deq.front()])<<"->"<<m<<endl;
				deq.pop_front();
				now--;
				
//				if(now==0){
//		//		cout<<"空了！\n";
//				}
			}
		//	cout<<"加入"<<a[i]<<"花费" <<now*(a[i]-a[i-1])<<endl; 
			m-=(now*(a[i]-a[i-1]));
			now++;maxx=max(maxx,now);
			deq.push_back(i);	
		}
	//	cout<<"现在“杂烩”里面有"<<now<<"，加入了"<<a[deq.back()]<<"导致m变为"<<m<<"，最大情况"<<maxx<<endl;
	}
	cout<<max(maxx,now);
	return 0;
} 
