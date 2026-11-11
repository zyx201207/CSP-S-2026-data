#include<bits/stdc++.h>
using namespace std;
int d[300005]={0};
bool flag[300005]={0};
set <int> f;
queue <int>g;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int d1;
		cin>>d1;
		int si=f.size();
		f.insert(d1);
		if(si!=f.size()){
			flag[d1]=1;
		}
		g.push(d1);
	}
	if(n==m &&n==2){
		cout<<2;
		return 0;
	}else if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		stack <int>h;
		queue <int>j;
		for(int z=0;z<i;z++)g.pop();
		for(int z=i;z<n;z++){
			int num=g.front();
			g.pop();
			j.push(num);
			g.push(num);
		}
		bool flag2[300005]={0};
		for(int z=i;z<n;z++){
			if(flag2[j.front()]==0){
				h.push(j.front());
				flag2[j.front()]=1;
				j.pop();

			}else{
				while(j.front()!=h.top()){
					flag2[h.top()]=0;
					h.pop();
				}
				j.back();
			}
		}
		while(!h.empty()){
			d[h.top()]++;
			h.pop();
		}
		
	}
	for(int i=0;i<300000;i++){
		if(flag[i]==1)cout<<d[i]<<" ";
	}
	return 0;
}

