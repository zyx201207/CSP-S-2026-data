#include<bits/stdc++.h>
using namespace std;
int n,m,a[229028],have[31];
int main(){
//	freopen("and.in","r",stdout);
//	freopen("and.out","w",stdin);
//	freopen("and.in","w",stdin);
//	freopen("and.out","r",stdout);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		for(int j=0;x;j++){
			have[j]+=x&1;
			x>>=1;
		}
	}
	for(int i=30;i>=0;i--){
		if(have[i]>=m){
			for(int j=0;j<=30;j++) have[j]=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if((a[j]>>i)&1){
					a[++cnt]=a[j];
					int x=a[j];
					for(int k=0;x;k++){
						have[k]+=x&1;
						x>>=1;
					}
				}
			}
			n=cnt;
		}
	}
	int ans=a[1];
	for(int i=2;i<=n;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
//这里还没有注释呢！
//有人和我玩原神和边狱巴士吗？
//加微信 15211078219 谢谢喵。
//我要上电视！！！ 
