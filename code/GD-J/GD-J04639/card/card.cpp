#include<bits/stdc++.h>
using namespace std;
queue<long long>q;
const int N=1e7+10;
long long a[N],s[N];
long long n,m;
bool t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			q.push(a[j]);
			if(t[a[j]]){
				while(1){
					q.pop();
					if(q.size()==1){
						break;
					}
				}
			}else{
				t[a[j]]=true;
			}
		}
		for(long long i=1;i<=m;i++){
			t[i]=false;
		}
		while(1){
			s[q.front()]++;
			q.pop();
			if(q.empty()) break;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
