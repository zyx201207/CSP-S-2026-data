//GZ-J00377 陈阳锦
#include<bits/stdc++.h>
using namespace std;
long long a[200010],s[200010],e[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long L=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=L+1;
		L+=a[i];
		e[i]=L;
	}
	long long l=1,r=L,i=1,j=n;
	while(l<=L&&r>=1){
		long long h,hl,hr;
		if(e[i]-l+1>r-s[j]+1) {

			h=r-s[j]+1;
			//cout<<h<<'r'<<r<<endl;
			hl=l+h,hr=s[j]-1;
			if(c[i]!=c[j]) ans+=h;
			l=hl,r=hr,j--;
		}
		else if(e[i]-l+1<r-s[j]+1) {

			h=e[i]-l+1;
			//cout<<h<<'l'<<l<<endl;
			hl=l+h,hr=r-h;
			if(c[i]!=c[j]) ans+=h;
			l=hl,r=hr,i++;
		}
		else if(e[i]-l+1==r-s[j]+1) {

			h=e[i]-l+1;
			//cout<<h<<'='<<l<<' '<<r<<endl;
			hl=l+h,hr=r-h;
			if(c[i]!=c[j]) ans+=h;
			l=hl,r=hr,i++,j--;
		}
	}
	cout<<ans/2;
	return 0;
}
