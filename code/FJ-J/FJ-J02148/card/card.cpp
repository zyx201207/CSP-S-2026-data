#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int A=3e5+7;
int a[N],b[A],c[A];
bool flag[A];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n>=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int z=1;z<=n;z++){
			for(int i=z;i<=n;i++){
				if(flag[a[i]]==false){
					flag[a[i]]=true;
					c[a[i]]=i;
				}
				else{
					for(int j=c[a[i]];j<i;j++){
						flag[a[j]]=false;
					}
					c[a[i]]=i;
					flag[a[i]]=true;
				}
			}
			for(int i=z;i<=n;i++){
				if(flag[a[i]]==true){
					b[a[i]]++;
					flag[a[i]]=false;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<' ';
		}
	}
	return 0;
} 
