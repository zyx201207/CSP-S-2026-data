#include<bits/stdc++.h>
using namespace std;
long long n,x,c,k,f,q,h;
long long a[200010],cnt[200010],cn[200010];
char y,b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>y;
		if(y==b[c]){
			a[c]+=x;
			cnt[c]+=x;
		}
		else{
			c++;
			a[c]=x;
			b[c]=y;
			cnt[c]=cnt[c-1]+x;
		}
		//cout<<c<<' '<<cnt[c]<<' '<<a[c]<<' '<<b[c]<<'\n';
	}
	//cout<<'\n';
	if(c==1){
		cout<<'0';
		return 0;
	}
	k=cnt[c]/2;
	//cout<<k<<' '<<c<<'\n';
	for(long long i=c;i>=1;i--){
		cn[i]=cn[i+1]+a[i];
		//cout<<i<<' '<<cn[i]<<' '<<a[i]<<' '<<b[i]<<'\n';
	}
	f=c;
	for(long long i=1;i<=c;i++){
		if(cnt[i]<k){
			for(long long j=f;j>=1;j--){
				if(cn[j]<cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'*'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					h=0;
				}
				if(cn[j]==cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'!'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					f=j-1;
					h=0;
					break;
				}
				if(cn[j]>cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-cn[j]+cnt[i]-h;
						//cout<<'#'<<i<<' '<<j<<' '<<a[j]-cn[j]+cnt[i]<<' '<<q<<'\n';
					}
					f=j;
					h=a[j]-cn[j]+cnt[i];
					break;
				}
			}
			continue;
		}
		if(cnt[i]==k){
			for(long long j=f;j>=1;j--){
				if(cn[j]<cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'*'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					h=0;
				}
				if(cn[j]==cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'!'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					f=j-1;
					h=0;
					break;
				}
				if(cn[j]>cnt[i]){
					if(b[j]!=b[i]){
						q+=a[j]-cn[j]+cnt[i]-h;
						//cout<<'#'<<i<<' '<<j<<' '<<a[j]-cn[j]+cnt[i]<<' '<<q<<'\n';
					}
					f=j;
					h=0;
					break;
				}
			}
			cout<<q;
			return 0;
		}
		if(cnt[i]>k){
			for(long long j=f;j>=1;j--){
				if(cn[j]<k){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'^'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					h=0;
				}
				if(cn[j]==k){
					if(b[j]!=b[i]){
						q+=a[j]-h;
						//cout<<'&'<<i<<' '<<j<<' '<<a[j]<<' '<<q<<'\n';
					}
					cout<<q;
					return 0;
				}
				if(cn[j]>k){
					if(b[j]!=b[i]){
						q+=a[j]-cn[j]+k-h;
						//cout<<'$'<<i<<' '<<j<<' '<<a[j]-cn[j]+k<<' '<<q<<'\n';
					}
					cout<<q;
					return 0;
				}
			}
		}
	}
}
