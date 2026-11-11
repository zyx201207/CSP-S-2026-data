#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
bool b[300005];
stack<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			b[s.top()]=0;
			s.pop();
		}
	}//...hyw
	/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    _int128 rp=INF;
    cout<<"rp=";//完美解决了RP溢出成负数的问题 
	while(1)cout<<"9";
	return 0;
}
	*/
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
} 
