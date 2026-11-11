//GZ-J00317 遵义市第四初级中学 王培祯 
#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,ans,b[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		cnt+=a[i];
		b[i]=b[i-1]+a[i];
	}
	long long l=(cnt/2),r=(cnt/2),m1,m2;
	if(cnt%2==0){
		r++;
	}
	else{
		l++,r++;
	}
//	cout<<l<<" "<<r<<" "<<cnt<<" ";
	for(int i=1;i<=n;i++){
		if(b[i]>=l){
			m1=i;
		}
		if(b[i]>=r){
			m2=i;
			break;
		}
	}
	if(m1==m2){
		if(l-b[m1-1]<=b[m2]-r){
			long long l1=l;
			l=b[m1-1],r+=(l1-l);//?
			if(r==b[m2]+1){
				m2++;
			}
			else{
				a[m2]=b[m2]-r+1;
			}
			m1--;
		}
		else{
			long long r1=r;
			r=b[m2]+1,l-=(r-r1);//?
			if(l==b[m1-1]){
				m1--;
			}
			else{
				a[m1]=l-b[m1-1]+1;
			}
			m2++;
		}
	}
//	cout<<m1<<" "<<m2<<" "<<l<<" "<<r<<" ";
	while(l>=1&&r<=cnt){
			if(s[m1]!=s[m2]){
				if(a[m1]<=a[m2]){
					ans+=a[m1];
					//cout<<l<<" "<<r<<" "<<m1<<" "<<m2<<" ";
					long long l1=l;
					l=b[m1-1],r+=(l1-l);//?
					a[m2]-=a[m1];
					if(a[m2]==0){
						m2++;
					}
					m1--;
				}
				else{
					ans+=a[m2];
					//cout<<l<<" "<<r<<" "<<m1<<" "<<m2<<" ";
					long long r1=r;
					r=b[m2]+1,l-=(r-r1);//?
					a[m1]-=a[m2];
					if(a[m1]==0){
						m1--;
					}
					m2++;
				}
			}
			if(s[m1]==s[m2]){
				if(a[m1]<=a[m2]){
					long long l1=l;
					l=b[m1-1],r+=(l1-l);//?
					a[m2]-=a[m1];
					if(a[m2]==0){
						m2++;
					}
					m1--;
				}
				else{
					long long r1=r;
					r=b[m2]+1,l-=(r-r1);//?
					a[m1]-=a[m2];
					if(a[m1]==0){
						m1--;
					}
					m2++;
				}
			}
	}
	cout<<ans;
	return 0;
}
