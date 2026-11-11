#include <iostream>
#include <cstring>
using namespace std;
long long n,m,a[500005],b[500005],p[300005],c,t,num[300005];
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p[j]=-1;
		}
		c=0;
		for(int j=i;j<=n;j++){
			b[++c]=a[j];
			num[b[c]]++;
			t=p[b[c]];
			if(t==-1){
				p[b[c]]=c;
			}
			else{
				for(;c>t;c--){
					p[b[c]]=-1;
					num[b[c]]--;
				}
				p[b[c]]=c;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
