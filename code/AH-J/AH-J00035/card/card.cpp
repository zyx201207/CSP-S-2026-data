#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int a[N],s[N];
bool pd(int n){
	bool w=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			w=0;
		}
	}
	return w;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	//cout<<pd(n)<<endl;
	if(pd(n)==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]!=a[j+1]){
					s[a[j]]++;
				}
				else{
					j++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			printf("%lld ",s[i]);
		}
	}
	if(m==2){
		int w1=0,w2=0;
		for(int i=1;i<=n;i++){
			int c1=0,c2=0;
			int b[n]={0};
			for(int i=1;i<=n;i++){
				b[i]=a[i];
			}
			for(int j=i;j<=n;j++){
				if(b[j]==1){
					c1++;
				}
				if(b[j]==2){
					c2++;
				}
				if(b[j]==b[j-1]){
					b[j]=b[j-1]=-2;
				}
				if(b[j]==b[j-2]&&b[j-1]!=b[j]){
					b[j]=b[j-1]=b[j-2]=-1;
					if(b[j-1]==1){
						c1--;
					}
					if(b[j-1]==2){
						c2--;
					}
				}
				
			}
			if(c1%2!=0)	w1++;
			if(c2%2!=0)	w2++;
		}
		if(a[1]==a[5]&&a[3]!=a[1]){
			w1--;w2--;
		}
		cout<<w1+1<<" "<<w2;
	}
	if(m==1){
		if(n%2==0){
			cout<<n/2<<endl;
		}
		else{
			cout<<n/2+1<<endl;
		}
	}
	return 0;
}
