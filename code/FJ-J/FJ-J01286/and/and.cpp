#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[35][200005];
set <long long> st,st2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j=a[i],wq=0;
		while(j){
			if(j%2){
				cnt[wq][++cnt[wq][0]]=a[i];
			}
			j/=2;
			wq++;
		}
	}
	for(int i=30;i>=0;i--){
		if(st.size()==0&&cnt[i][0]>=m){
			for(int j=1;j<=cnt[i][0];j++){
				st.insert(cnt[i][j]);
			}
		}else if(cnt[i][0]>=m){
			int c=0;
			st2.clear();
			for(int j=1;j<=cnt[i][0];j++){
				if(st.count(cnt[i][j]))c++;
				st2.insert(cnt[i][j]);
			}
			if(c>=m){
				for(long long i:st){
					if(st2.count(i)==0){
						st.erase(i);
					}
				}
			}
		}
	} 
	if(st.size()==0)cout<<0;
	else{
		int ans=0;
		for(long long i:st){
			if(ans!=0){
				ans&=i;
			}else{
				ans=i;
			}
		}
		cout<<ans;
	}
	return 0;
}
