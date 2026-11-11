#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,y,t;
struct aa {
	long long c;
	long long place;
};
bool cmp2(aa b,aa d){
	if(b.c==d.c)
		return b.place<d.place;
	return b.c<d.c;
}
long long s[500010],x;

aa a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);//shengxu
	for(long long i=1;i<n;i++){
		a[i].c=s[i+1]-s[i];
		a[i].place=i;
	}

		sort(a+1,a+n,cmp2);//chazhipaixu
		for(long long i=0,j=1;j<n,i<=m;j++){			
			if(a[j].c!=0){
				if(a[j].c<m-i){
					
					i+=a[j].c;
					s[a[j].place]+=a[j].c;
					for(long long k=n-1;k>=1;k--){
						if(a[k].place==a[j].place-1){
							a[k].c+=a[j].c;
							break;
						}
					}
						
					a[j].c=0;
					sort(a+1,a+n,cmp2);
				}
				else if(a[j].c==m-i){
					s[a[j].place]+=a[j].c;
					break;
				}
				else{
					break;
				}
			}
			else{
				continue;
			}
			
		}

	for(long long i=1;i<=n;){
		x=s[i];
		for(long long j=i;j<=n;j++){
			if(s[j]==x){
				ans++;
				if(j==n){
					cout<<max(ans,y);
					return 0;
				}
			}
			else{
				y=max(y,ans);
				ans=1;
				i=j;
				break;
				
			}
			
		}
		y=max(y,ans);
	}
	cout<<y;
	return 0;
}
