#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;//5e5,3e5
int a[500005];
int used[300005];//点数i的上一个位置 
int s[300005],head=0;//储存的栈 

int tot[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	if(m==1){
		cout<<n; return;
	}
	if(m==2){
		for(int i=1; i<=n; ++i){
			cin>>a[i];
		}
		
	}
	if(n<=5000){//48pts?
		for(int i=1; i<=n; ++i){
			memset(used,0,sizeof used);
			head=0;
			for(int j=i; j<=n; ++j){
				if(!used[a[j]]||used[a[j]]>head||s[used[a[j]]]!=a[j]){
					head++;
					s[head]=a[j];
					used[a[j]]=head;
				}
				else{
					head=used[a[j]];
				}
			}
			for(int j=1; j<=head; ++j) tot[s[j]]++;
		}
		for(int i=1; i<=m; ++i)cout<<tot[i]<<" ";
	}
}
/*
{
    "md5_check": [
        {
            "name": "cspj.zip",
            "md5": "f34b8d295f2e1639df13f659f649e00e"
        }
    ],
    "root_path": "D:\\",
    "regex": "^GD-J\\d{5}$",
    "problems": [],
    "start_time": "2026-10-31T08:30:00+08:00",
    "end_time": "2026-10-31T12:00:00+08:00",
    "size_limit_kb": 100,
    "problem_regex": "^{0}\\\\{0}\\.(cpp|c|pas)$",
    "problem_extern": true
}
*/








































//

