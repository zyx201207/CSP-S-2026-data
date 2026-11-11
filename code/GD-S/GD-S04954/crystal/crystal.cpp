#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a=0,b=0;
	cin>>a>>b;
	vector<int> c;
	for(int i=0;i<a;i++){
		int g=0;
		cin>>g;
		c.push_back(g);
	}
	sort(c.begin(),c.end());
	priority_queue<long long> pq; 
	for(long long i=1;i<a;i++){
		long long cost=0;
		int yh=0;
		int ghh=0;
		for(long long o=0;o<i;o++){
			cost=cost+c[i]-c[o];
		}
        if(cost>b){
        	for(long long o=0;o<i;o++){
        		cost-=c[i]-c[o];
        		yh=o+1;
        		if(i+1-yh<pq.top()){
        			ghh=1;
        			break;
				}
			}
		}
		if(ghh==1) break;
		pq.push(i+1);
	}
	cout<<pq.top();
	return 0;
} 
