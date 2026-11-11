#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,tmp;
string s;
struct str{
	char c;
	long long t;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		m+=a[i].t;
	}
	long long k=1,l=n,tmp=0;//Ë«Ö¸Õë
	while(tmp<m/2){
		if(a[k].t<a[l].t){
			if(a[k].c==a[l].c){
				k++;
				tmp+=a[k-1].t;
				a[l].t-=a[k-1].t;
			}else{
				ans+=a[k].t;
				k++;
				tmp+=a[k-1].t;
				a[l].t-=a[k-1].t;
			}
		}else if(a[k].t>a[l].t){
			if(a[k].c==a[l].c){
				l--;
				tmp+=a[l+1].t;
				a[k].t-=a[l+1].t;
			}else{
				ans+=a[l].t;
				l--;
				tmp+=a[l+1].t;
				a[k].t-=a[l+1].t;
			}
		}else if(a[k].t==a[l].t){
			if(a[k].c==a[l].c){
				k++;
				l--;
				tmp+=a[l+1].t;
			}else{
				ans+=a[l].t;
				k++;
				l--;
				tmp+=a[l+1].t;
			}
		}
	}
	cout<<ans;
}
