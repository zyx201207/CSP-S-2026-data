#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200005],m,w[200005],maxa=-0x3f3f3f3f;
bool b[200005];
void f(int x,int y){
	if(x>n){
		if(y<m){
			return ;
		}else if(y==m){
			int pos;
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					pos=i;
					break;
				}
			}
			LL sum=a[pos];
			for(int i=pos+1;i<=n;i++){
				if(b[i]!=0){
					sum=(sum&a[i]);
				}
			}
			maxa=max(maxa,sum);
			return ;
		}
	}else{
		if(y==m){
			int pos;
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					pos=i;
					break;
				}
			}
			LL sum=a[pos];
			for(int i=pos+1;i<=n;i++){
				if(b[i]!=0){
					sum=(sum&a[i]);
				}
			}
			maxa=max(maxa,sum);
			return ;
		}
	}
	b[x]=1;
	f(x+1,y+1);
	b[x]=0;
	f(x+1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		f(1,0);
		cout<<maxa;
	}else if(n<=2000){
		if(m==1){
			sort(a+1,a+n+1);
			cout<<a[n];
		}else if(m==2){
			LL maxa=-0x3f3f3f3f;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					maxa=max(maxa,a[i]&a[j]);
				}
			}
			cout<<maxa;
		}else{
			LL sum=a[1];
			for(int i=2;i<=n;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}
	}else{
		if(m==n-1){
			LL maxa=-0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				if(i==1){
					LL ans=a[2];
					for(int i=3;i<=n;i++){
						ans=ans&a[i];
					}
					maxa=max(maxa,ans);
				}else{
					LL ans=a[1];
					for(int j=2;j<=n;j++){
						if(i!=j){
							ans=ans&a[j];
						}
					}
					maxa=max(maxa,ans);
				}
			}
			cout<<maxa;
		}else{
			f(1,0);
			cout<<maxa;
		}
	}
	return 0;
}
