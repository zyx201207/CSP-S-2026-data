#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>l(n);
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(m==1)cout<<1;
	if(m==2){
		queue<int> q;
		int a=0,b=0;
		int ans=0;
		for(auto s:l){
			if(a==0&&b==0)a=s;
			else if(a==0&&b!=0&&s!=b)a=s;
			else if(b==0&&a!=0&&s!=a)b=s;
		}
		for(int i=0;i<n;i++){
			bool F=0,F1=0;
			for(int j=i;j<n;j++){
				if(F&&l[j]==a){
					while(q.front()!=b)q.pop();
					q.push(l[j]);
				}
				else if(l[j]==a)F=1;
				if(F1&&l[j]==b){
					while(q.front()!=a)q.pop();
					q.push(l[j]);
				}
				else if(l[j]==b)F1=1;
			}
			while(q.front()!=i){
				q.pop();
				if(q.empty())break;
			}
			if(!q.empty())ans++;
		}
		cout<<ans;
	}//CCFwoaini
	return 0;
}
