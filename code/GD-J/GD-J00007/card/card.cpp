#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a1,A[210000],cnt[210000];
	queue<long long>a;
	stack<long long>table;
	long long cnt2[210000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1;
		a.push(a1);
		A[i]=a1;
	}
	long long z=0;
	for(long long i=0;i<n;i++){
		if(cnt2[a.front()]=0){
			table.push(a.front());
			cnt2[a.front()]=1;
			a.pop();
		}
		cnt[0]=3;
		cnt[1]=1;
		cnt[2]=4;
	}
	for(int i=0;i<m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
