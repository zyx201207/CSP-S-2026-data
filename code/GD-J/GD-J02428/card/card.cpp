#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[500010],b[500010],s[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=1;
		for(int i=1;i<=n;i++){
			b[i]=0;
			s[i]=0;
		}
		for(int j=i;j<=n;j++){
			int c=a[j];//当前打出的牌 
			if(b[c]!=0){
				for(int p=b[c]+1;p<k;p++){
					s[a[p]]=0;
					b[a[p]]=0;
				}
				k=b[c]+1;
			}
			else{
				b[c]=k;
				s[c]=1;
				k++;
			}
		}
		for(int i=1;i<=m;i++) cout<<b[i]<<' ';
		for(int i=1;i<=m;i++) if(s[i]) ans[i]++;
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
