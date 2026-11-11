#include<iostream>
using namespace std;
int n;
struct N{
	int a;
	char c;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].c;
	for(int i=1;i<=n;i++) b[i]=a[n-i+1];
	long long i=0,j=0,p=0,q=0;
	long long ans=0;
	for(int t=1;t<=2*n;t++){
		if(p>=q){
			j++;
			q+=b[j].a;
			if(a[i].c!=b[j].c&&i!=0){
				ans+=min(p,q)-(q-b[j].a);
			}
		}
		else{
			i++;
			p+=a[i].a;
			if(a[i].c!=b[j].c&&j!=0){
				ans+=min(p,q)-(p-a[i].a);
			}
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}
		
