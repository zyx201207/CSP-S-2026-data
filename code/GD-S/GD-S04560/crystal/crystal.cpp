#include<bits/stdc++.h>

using namespace std;

priority_queue<long long,vector<long long>,greater<long long> > pq;
priority_queue<long long> pq2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		long long inpu;
		cin >> inpu;
		pq.push(inpu);
		pq2.push(inpu);
	}
	long long m2 = m;
	long long res = 1;
	long long zhi = pq.top();
	long long change = 1;
	pq.pop();
	while(!pq.empty()){
		long long tt = pq.top();
		pq.pop();
		if(tt!=zhi)
		{
			long long com = change*(tt-zhi);
			if(m >= com){
				m -= com;
				zhi = tt;
			}else{
				break;
			}
		}
		change++;
		res++;
	}
	long long res2 = 1;
	long long zhi2 = pq2.top();
	long long change2 = 1;
	pq2.pop();
	while(!pq2.empty()){
		long long tt = pq2.top();
		pq2.pop();
		if(tt!=zhi2)
		{
			long long com = change2*(zhi2-tt);
			if(m2 >= com){
				m2 -= com;
				zhi2 = tt;
			}else{
				break;
			}
		}
		change2++;
		res2++;
	}
	cout << max(res,res2);
	
	return 0;
} 
