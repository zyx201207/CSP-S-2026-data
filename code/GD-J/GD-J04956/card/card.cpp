#include<iostream>
#include<stack>
using namespace std;
long long a[500010];
long long cnt[300010];
long long sum[300010];
stack<long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s.empty()){
				s.push(a[j]);
				cnt[a[j]]++;
				sum[a[j]]++;
			}
			else if(sum[a[j]]){
				while(s.top()!=a[j]){
					cnt[s.top()]--;
					sum[s.top()]--;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				cnt[a[j]]++;
				sum[a[j]]++;
			}
		}
		while(!s.empty()){
			s.pop();
		}
		for(int j=1;j<=m;j++){
			sum[j]=0;
		}
	}
	for(int i=1;i<=300000;i++){
		if(cnt[i]!=0) cout<<cnt[i]<<" ";
	}
	return 0;
}
