#include<bits/stdc++.h>
using namespace std;
const int N=30005;
int cnt[N],a[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> sta;
		int cd=0;
		for(int j=i;j<=n;j++){
			if(cd!=0){
			for(int st=0;st<cd;st++){
				if(s[st]==a[j]){
					for(int p=cd-1;p>0;p--){
						if(s[p]==s[st]){
							sta.pop();
							s[p]=0;
							cd--;
							break;
						}else{
							sta.pop();
							s[p]=0;
							cd--;
						}
					}
					break;
				}
			}
		}else{
			sta.push(a[j]);
			s[j]=a[j];
			cd++;
		}
		for(int j=0;j<cd;j++){
			cnt[s[j]]++;
		}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
