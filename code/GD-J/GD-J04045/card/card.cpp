#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int a[N]{};
int b[N]{};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
	}
	int ans[N]{};
	for(int i=1;i<=n;i++){
		stack<int>st;
		int cnt[N]{};
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				st.push(a[j]);
				cnt[a[j]]++;
			}
			else{
				while(!st.empty()){
					int temp=st.top();
					st.pop();
					cnt[temp]--;
					if(temp==a[j]) break;
				}
				st.push(a[j]);
				cnt[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]>0) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
