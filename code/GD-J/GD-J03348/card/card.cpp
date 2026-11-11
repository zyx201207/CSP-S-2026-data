#include<iostream>
#include<stack>
using namespace std;
int n,m,a[500003],cnt[300003];
stack<int> s;
bool check[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[j];
			while(check[x]){
				check[s.top()]=0;
				s.pop();
			}
			s.push(x);
			check[x]=1;
		}
		for(int k=1;k<=m;k++){
			cnt[k]+=check[k];
			check[k]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
} 
