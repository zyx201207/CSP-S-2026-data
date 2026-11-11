#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=2e5+10;
int a[N];//卡牌 
int k[N];//储存桌面上的牌 
int p[M];//统计桌面上的牌 
int t[M];//最终统计点数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=1;
			break;
		}
	}
	if(!flag){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		int len=1;
		memset(k,0,sizeof(k));
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			if(p[a[j]]==0){
				p[a[j]]=len;
				k[len]=a[j];
				len++;
			}
			else{
				int lenl=p[a[j]];
				for(int l=p[a[j]];l<=len;l++){
					p[k[l]]=0;
					k[l]=0;
				}
				len=lenl;
				k[len]=a[j];
				p[a[j]]=len;
				len++;
			}
		}
		for(int i=1;i<=m;i++){
			if(p[i]!=0){
				t[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
