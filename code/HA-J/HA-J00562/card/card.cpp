#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=5e5,MAX_M=3e5;
int n,m;
queue<int>a,na;
vector<int>b;
int cnt[MAX_M+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	b.push_back(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int _a;
		cin>>_a;
		a.push(_a);
	}
	for(int wtf=1;wtf<=n;wtf++){
		for(int i=1;i<=a.size();i++){
			int current=a.front();
			a.pop();
			for(int j=1;j<b.size();j++){
				if(b[j]==current){
					for(int k=b.size()-1;k>=j;k--){
						na.push(b.back());
						b.pop_back();
					}
					break;
				}
			}
			b.push_back(current);
		}
		for(int j=1;j<b.size();j++){
			cnt[b[j]]++;
		}
		a=na;
		while(!na.empty())na.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
