#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],ans,cnt,num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,s=1;
	
	for(int i=1;i<=m;i++){
		for(int j=l;j<=n;j++){
			l=l+j;
			if(a[j]==a[1]){
				b[1]=a[1];
			}
			s++;
			b[s]=a[j];
			if(b[j]==1){
				ans++;
			}else if(b[j]==2){
				cnt++;
			}else if(b[j]==3){
				num++;
			}
		}
	}
	cout<<ans<<" "<<cnt<<" "<<num;
	return 0;
}
//4 3
//1 2 1 3
//10 3
//3 1 2 1 3 2 3 1 2 1

