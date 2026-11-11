#include<bits/stdc++.h>
using namespace std;
const int Mn=2e5+5;
int n,a[Mn],zhongshu=0,houzui[Mn];
long long sum;
char c[Mn];
bool f=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	houzui[n+1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		zhongshu+=a[i];
	}
	for(int i=n;i>=1;i--){
		houzui[i]+=houzui[i+1]+a[i];
	}
	int i=1,j=n;
	while(f==true){
		int l=0,b=0;
		b=a[i]-a[j];
		if(i==j){
			f=false;
			sum+=a[i];
		}
		if(c[i]==c[j]){
			if(b>0){
				a[i]-=a[j];
				l=1;
			}else if(b<0){
				a[j]-=a[i];
				l=2;
			}else{
				l=0;
			}
		}else{
			if(b>0){
				sum+=a[j];
				a[i]-=a[j];
				l=1;
			}else if(b<0){
				sum+=a[i];
				a[j]-=a[i];
				l=2;
			}else{
				sum+=a[i];
				l=0;
			}
		}
		if(i+1==j){
			f=false;
		}
		if(l==1){
			j--;
		}else if(l==2){
			i++;
		}else{
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
}
