#include<bits/stdc++.h>
using namespace std;
int a[510000],tong[310000],flag[310000],zhong[310000];
//vector<int> e;
stack<int> e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			flag[j]=0;
		}
		for(int j=i;j<=n;j++){
			//cout<<a[j]<<' ';
			if(!flag[a[j]]){
				//cout<<1;
				flag[a[j]]=1;
				e.push(a[j]);
			}
			else{
				if(!e.empty()){
					int now;
					while(!e.empty()){
						now=e.top();
						e.pop();
						if(now==a[j])break;
					}
				}
				e.push(a[j]);
				for(int j=1;j<=m;j++){
					flag[j]=0;
				}
				
			}
		}
		int len=e.size();
		//cout<<len<<' ';
		cout<<i<<' ';
		while(!e.empty()){
			int now2=e.top();
			e.pop();
			tong[now2]++;
			cout<<' '<<now2<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	} 
	return 0;
}/*4 3
 1 2 1 3
 
10 3
3 1 2 1 3 2 3 1 2 1
*/

