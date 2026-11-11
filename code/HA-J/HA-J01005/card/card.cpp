#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],pos,ans[300005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		pos=0;
		for(int i=j;i<=n;i++){
			if(t[a[i]]==0){
				pos++;
				t[a[i]]=pos;
				s[pos]=a[i];
			}
			else{
				for(int j=t[a[i]]+1;j<=pos;j++){
					t[s[j]]=0;s[j]=0;
				}
				pos=t[a[i]];
			}
		
		}
		for(int i=1;i<=pos;i++){
			ans[s[i]]++;
			t[s[i]]=0;
			
			s[i]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
