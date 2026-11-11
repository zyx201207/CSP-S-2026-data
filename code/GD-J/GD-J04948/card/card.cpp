#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],h,cnt[300005],t;
vector<int> s;
stack<int> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			h=-1;
			t=0;
			while(!s.empty()){
				t++;
				c.push(s.back());
				if(s.back()==a[j]){
					h=t;
					break;
				}
				s.pop_back();
			}
			h=t-h;
			while(!c.empty()){
				s.push_back(c.top());
				c.pop();
			}
			if(h!=-1){
				for(int k=h;k<=n;k++) s.pop_back();
				s.push_back(a[j]);
			}
			else s.push_back(a[j]);
		}
		while(!s.empty()){
			cnt[s.back()]++;
			s.pop_back();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
}
