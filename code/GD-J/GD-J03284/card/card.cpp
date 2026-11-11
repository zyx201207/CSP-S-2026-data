#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+10;
//struct node{
//	int s,id;
//}b[N];
int n,m,a[N],b[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++) b[i]=0;
		for(int i=k;i<=n;i++){
			if(b[a[i]]!=0){
				for(int j=b[a[i]];j<=i;j++){
					b[a[j]]=0;
				}
				b[a[i]]=i;
			}else{
				b[a[i]]=i;
			}
			//cout<<a[i]<<" "<<b[a[i]]<<endl;
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0) ans[i]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

