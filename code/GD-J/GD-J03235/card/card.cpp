#include<iostream>
#include<stack>
using namespace std;
int n,m,a[500005],x[300005],cnt[300005];
stack<int> t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[a[j]]++;
			if(x[a[j]]>1){
				while(x[a[j]]>1){
					x[t.top()]--;
					t.pop();
				}
			}
			t.push(a[j]);
		}
		while(!t.empty()){
			cnt[t.top()]++;
			x[t.top()]--;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
 } 
