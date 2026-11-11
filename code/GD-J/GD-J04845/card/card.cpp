#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> q;
	vector<long long> cards;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		q.push_back(a);
	}
	long long ans=0;
	for(long long i=0;i<m;i++){
		long long x=q[i];
		cards.push_back(x);
		q.pop_front();
		for(long long j=0;j<i;j++){
			if(cards[i]==cards[j]){
				cards.erase(j,i);
				for(long long k=0;k<i-j;k++){
					q.push_back(cards[j]);
				}
			}
		}
	}
	for(long long i=0;i<cards.size();i++){
		cout<<cards[i]<<" ";
	}
	return 0;
} 
