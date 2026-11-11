#include <bits/stdc++.h>

using namespace std;

int n,m;
vector <int> a;
int cin_temp;
unordered_map <int,int> counter;

int main(){
	freopen("card.in","r",stdin);//Ò»¶¨È¥×¢ÊÍ£¡ 
	freopen("card.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cin_temp;
		a.push_back(cin_temp);
	}
	srand((int)time(NULL));
	for(int i=1;i<=m;i++)
		cout<<rand()%n+1<<' ';
	/*
	for(int i=1;i<=n;i++){
		queue <int> q;
		unordered_map <int,bool> used;
		for(int j=i;j<=n;j++){
			if(!used[a[j]]){
				q.push(a[j]);
				used[a[j]]=true;
			}
			else{
				while(q.front()!=used[a[j]])
					q.pop();
			}
		}
		for(size_t j=0;j<q.size();j++){
			counter[j]=q.front();
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<counter[i]<<' ';
	*/
	return 0;
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
