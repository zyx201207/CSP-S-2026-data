#include<bits/stdc++.h>
#define int long long
using namespace std;
struct andand{
	int yige,zhi;
};
andand b[200010];
int n,m,a[200010];
int yidegeshu(int x){
	int s=0;
	while(x!=0){
		s+=1;
		x=(x&(x-1));
	}
	return s;
}
bool bijiao(andand a1,andand a2){
	if(a1.yige==a2.yige) return a1.zhi>a2.zhi;
	else return a1.yige>a2.yige;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int ma=-1e9;
		for(int i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma<<endl;
		return 0;
	}else if(m==2){
		int ma=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<endl;
	}else if(m==n-1){
		int ma=-1e9;
		for(int i=1;i<=n;i++){
			int shu;
			if(i==1){
				shu=a[2];
				for(int j=3;j<=n;j++) shu=shu&a[j];
			}else if(i==2){
				shu=a[1];
				for(int j=3;j<=n;j++) shu=shu&a[j];
			}else{
				shu=a[1];
				for(int j=2;j<=n;j++){
					if(i==j) continue;
					shu=shu&a[j];
				}
			}
			ma=max(ma,shu);
		}
		cout<<ma<<endl;
	}else if(m==n){
		int shu=a[1];
		for(int i=2;i<=n;i++) shu=shu&a[i];
		cout<<shu<<endl;
	}else{
		for(int i=1;i<=n;i++) b[i].zhi=a[i];
		for(int i=1;i<=n;i++) b[i].yige=yidegeshu(b[i].zhi);
		sort(b+1,b+n+1,bijiao);
		int shu=a[1];
		for(int i=2;i<=m;i++) shu&=a[i];
		cout<<shu<<endl;
	}
	return 0;
}
