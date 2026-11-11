#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,sum[N],cnt=0,s[N],a[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			sum[j]=0;
			s[j]=0;
		}
		for(int j=i;j<=n;j++){
			bool p=0,x=0;
			for(int k=1;k<=cnt;k++){
				if(s[k]==a[j]){
					p=1;
					x=k;
					break;
				}
			}
			if(p==1){
				for(int k=x+1;k<=cnt;k++){
					sum[s[k]]--;
					s[k]=0;
				}
				s[x+1]=a[j];
				sum[a[j]]++;
				cnt=x+1;
			}
			else{
				cnt++;
				sum[a[j]]++;
				s[cnt]=a[j];
			}
		}
		for(int k=1;k<=m;k++){
			if(sum[k]>0){
				ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
