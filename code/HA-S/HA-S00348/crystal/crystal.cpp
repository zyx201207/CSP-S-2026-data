#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int b[500010],cnt1[100010];
struct node{
	int val,num;
}a[500010];
LL n,m,L,R,ans,cnt,mx=1;
bool f=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin.tie(0);
	if(n<=5000&&m<=1000000){
		for(int i=1;i<=n;i++){
			cin>>b[i];
			cnt++;
		}
		sort(b+1,b+1+n);
		while(cnt){
			LL sum=0;
			for(int i=1;i<=cnt;i++){
				sum+=(b[cnt]-b[i]);
			}
			if(m-sum>=0){
				ans=cnt;
				break;
			}
			cnt--;
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>b[i];
			cnt1[b[i]]++;
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i+=cnt1[b[i]]){
			a[++cnt].val=b[i];
			a[cnt].num=cnt1[b[i]];
		}
		for(int i=2;i<=cnt;i++){
			if(a[mx].num<a[i].num){
				mx=i;
			}
		}
		ans+=a[mx].num;
		L=mx-1;
		R=mx+1;
		while(m>0){
			f=true;
			if(L<1&&R>n){
				break;
			}else if(L<1){
				for(int i=R-1;i>=1;i--){
					for(int j=1;j<=a[i].num;j++){
						m-=(a[R].val-a[i].val);
						if(m<0){
							f=false;
							break;
						}else if(m==0){
							ans++;
							f=false;
							break;
						}
						ans++;
					}
					if(!f){
						break;
					}
				}
				if(f){
					for(int i=1;i<R;i++){
						a[i].val=a[R].val;
					}
					R++;
				}
			}else if(R>n){
				LL cl=a[mx].val-a[L].val;
				for(int i=1;i<=a[L].num;i++){
					m-=cl;
					if(m<0){
						f=false;
						break;
					}else if(m==0){
						ans++;
						f=false;
						break;
					}
					ans++;
				}
				if(f){
					a[L].val=a[mx].val;
					L--;
				}
			}else{
				LL cl=a[L].num*(a[mx].val-a[L].val),cr;
				for(int i=1;i<R;i++){
					cr+=a[i].num*(a[R].val-a[i].val);
					if(cr>cl){
						break;
					}
				}
				if(cl<=cr){
					for(int i=1;i<=a[L].num;i++){
						m-=cl;
						if(m<0){
							f=false;
							break;
						}else if(m==0){
							ans++;
							f=false;
							break;
						}
						ans++;
					}
					if(f){
						a[L].val=a[mx].val;
						L--;
					}
				}else if(cl>cr){
					for(int i=R-1;i>=1;i--){
						for(int j=1;j<=a[i].num;j++){
							m-=(a[R].val-a[i].val);
							if(m<0){
								f=false;
								break;
							}else if(m==0){
								ans++;
								f=false;
								break;
							}
							ans++;
						}
						if(!f){
							break;
						}
					}
					if(f){
						for(int i=1;i<R;i++){
							a[i].val=a[R].val;
						}
						R++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
