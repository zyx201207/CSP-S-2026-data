#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int ans[300005];
int arr[500005];
int b[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<n;j++){
			if(b[arr[j]]==0){
				s.push(arr[j]);
				b[arr[j]]=1;
			}
			else{
				while(s.size()&&s.top()!=arr[j]) {
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		while(s.size()){
			a=s.top();
			ans[a]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

