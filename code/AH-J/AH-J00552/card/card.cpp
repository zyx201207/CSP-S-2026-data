#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],cnt2[500005],lst[500005];
stack<int>st;
bool f=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f|=(a[i]<a[i-1]);
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			int l=1,r=n;
			while(l<r){
				int mid=(l+r+1)/2;
				if(a[mid]>i){
					r=mid-1;
				}else{
					l=mid;
				}
			}
			cout<<l<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cnt[j]=0;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					cnt[st.top()]--;
					st.pop();
				}
			}else{
				st.push(a[j]);
				cnt[a[j]]++;
			}
		}
		while(!st.empty()){
			cnt2[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt2[i]<<" ";
	}
	return 0;
}
