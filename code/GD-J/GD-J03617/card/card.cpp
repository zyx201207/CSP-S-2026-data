#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans[100001],t[100001],b[200001],s,x=0,y=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				x++;
				y++;
			}
			else{
				if(a[n]==1){
					x++;
				}
				else
				y++;
			}
		}
		cout<<x<<" "<<y;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s=0;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]++;
				s++;
				b[s]=a[j];
			}else{
				for(int k=s;k>=1;k--){
					if(a[k]==a[j]){
						break;
					}
					t[b[s]]--;
					b[s]=0;
					s--;
				}
			}
		}
		for(int k=1;k<=s;k++){
			ans[b[k]]=ans[b[k]]+1;
			b[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
