#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,a[500005],k,m,mao,ans[500005];
vector<int>s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		mao=max(mao,a[i]);
		ans[i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=0;k<s.size();k++){
				if(s[k]==a[j]){
					s[k]=0;
					for(int q=k;q<s.size();q++)s[q]=0;
					break;
				}
			}
			s.push_back(a[j]);
		}
		for(int j=0;j<s.size();j++){
			if(ans[s[j]]==-1)ans[s[j]]=0;
			ans[s[j]]++;
		}
		s.clear();
	}
	for(int i=1;i<=mao;i++){
		if(ans[i]!=0){
			if(ans[i]==-1)cout<<0;
			else cout<<ans[i]<<' ';
		}
	}
	return 0;
}

