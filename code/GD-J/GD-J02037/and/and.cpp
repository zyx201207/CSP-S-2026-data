#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b,f[N][40],ans[40],answ[40],len=1;
void fl(int h,int k){
	int i=35;
	while(h){
		f[k][i]=h%2;
		h/=2;
		i--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		fl(a[i],i);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=35;i++){
		b=0;
		for(int j=1;j<=n;j++){
			b+=f[j][i];
		}
		if(b>=m){
			for(int j=1;j<=n;j++){
				if(f[j][i]==1){
					ans[len]=j;
					len++;
				}
			}
			break;
		}
	}
	len-=1;
	for(int i=1;i<=35;i++){
		bool flag=true;
		for(int j=1;j<=len;j++){
			if(f[ans[j]][i]==0){
				flag=false;
				break;
			}
		}
		if(flag){
			answ[i]=1;
		}
	}
	unsigned long long da=0,la=1;
	for(int i=35;i>=1;i--){
		if(answ[i]==1)da+=la;
		la*=2;
	}
	cout<<da;
	return 0;
}
