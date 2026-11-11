#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
ll m,n;
ll s[500010],a[500010],ans[500010],box[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
		box[i]=s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			s[j]=box[j];
			a[s[j]]++;
			if(a[s[j]]>1){
				for(int k=j-1;k>=i;k--){
					if(s[k]==s[j]){
						for(int d=j-1;d>=k;d--){
							a[s[d]]--;
							s[d]=0;
						}
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=a[j];
			a[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		ans[box[n-1]]=n;
		cout << ans[i] << " ";
	}
	return 0;
}
