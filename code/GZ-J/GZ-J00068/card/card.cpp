//GZ-J00068，阮辰允，贵阳市白云区华师一学校
#include <bits/stdc++.h>
using namespace std;
int n,m,ans[300001],a[500001];
bool ins[300001];
stack<int> st;  
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				ans[1]++;
				ans[2]++;
			}
			else{
				ans[a[n]]++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			while(st.size()){
				ins[st.top()]=0;
				st.pop();
			}
			for(int j=i;j<=n;j++){
			    if(ins[a[j]]){
			    	while(st.size()&&st.top()!=a[j]){
			    		ins[st.top()]=0;
			    		st.pop();
					}
				}
				else{
					ins[a[j]]=1;
					st.push(a[j]);
				}
		    }
		    for(int j=1;j<=m;j++){
		    	if(ins[j]){
		    		ans[j]++;
				}
			}
		}
    }
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
