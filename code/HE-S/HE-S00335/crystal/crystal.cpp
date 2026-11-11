#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ma=-1e9;
void kun(int x){
	int k=0,m2=m,ans=0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			k++;
			b[k]=x-a[i];
		}else{
			break;
		}
	}
	for(int i=k;i>=1;i--){
		if(m2>=b[i]){
			ans++;
			m2-=b[i];
		}
	}
	ma=max(ma,ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]<=1e5){//±©Á¦  50-60 
		for(int i=a[1];i<=a[n];i++){
			kun(i);
		}
		cout<<ma;
	}else if(n>10000){
		int cha=a[2]-a[1],ans=0;
		if(cha==1){//A  15
			int k=0;
			while(m>=k){
				ans++;
				m-=k;
				k++;
			}
			if(ans>n) ans=n;
			cout<<ans;
		}else{//B 15
			for(int i=0;i<cha;i++){
				int m2=m,k=i,ans=0;
				while(m2>=k){
					ans++;
					m2-=k;
					k+=cha;
				}
				ma=max(ma,ans);
			}
			if(ma>n) ma=n;
			cout<<ma;
		}
	}
	return 0;
}
/*
1  2  4  8  9
1  3  7  15  24
*/
