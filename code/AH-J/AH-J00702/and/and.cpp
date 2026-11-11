#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool si[32],sj[32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	long long sm=-1,sn=1e17,s=-1,ss,sss,b;
	bool c=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]>sm) sm=a[i];
		if (a[i]<sn) sn=a[i];
	}
	if (m==1) cout<<sm;
	else if (m==n) cout<<sn;
	
	else if (m==2){
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				b=a[i];k=0;
				memset(si,0,sizeof(si));
				memset(sj,0,sizeof(sj));
				while (b>0){
					si[k]=b%2;
					b/=2;
					k++;
				}
				b=a[j];k=0;
				while (b>0){
					sj[k]=b%2;
					b/=2;
					k++;
				}
				for (int q=1;q<=30;q++){
					if (si[q]&&sj[q]) {
						sss=1;
						for (int w=1;w<=q;w++) sss*=2;
						ss+=sss;
					}
				}
				if (ss>s) s=ss;
			}
		}
		cout<<s;
	}
	else {
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
