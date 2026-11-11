//GZ-J00397 张颜淏 贵阳市云岩区中天中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;

int n,m;
int a[N],cnt[N];
bool liv[N];
deque<int>had;
deque<int>ont;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)had.push_back(a[j]);
		while(!had.empty()){
			int pok=had.front();
			had.pop_front();
			if(liv[pok]){
				while(ont.back()!=pok){
					liv[ont.back()]=0;
					ont.pop_back();
				}
				liv[ont.back()]=0;
				ont.pop_back();
			}
			ont.push_back(pok);
			liv[pok]=1;
		}
		while(!ont.empty()){
			int pok=ont.front();
			cnt[pok]++;
			ont.pop_front();
			liv[pok]=0;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}



