#include<iostream>
#include<queue>
using namespace std;
int n,m,a[200010],cnt[200010]={0},num[200010]={0};
deque<int>vt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i>=0;i--){
		int pos=-1,cntpos=0;
		for(int d:vt){
			if(d==a[i]){
				pos=cntpos;
				break;
			}
			cntpos++;
		}
		if(pos==-1){
			vt.push_front(a[i]);
			num[a[i]]++;
			for(int i=1;i<=m;i++) cnt[i]+=num[i];
		}
		else{
			for(int d:vt){
				if(pos<=0) break;
				pos--;
				vt.pop_front();
				num[d]--;
			}
			for(int i=1;i<=m;i++) cnt[i]+=num[i];
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
