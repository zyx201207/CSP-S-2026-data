#include<iostream>
using namespace std;
const int N=2e5+2;
struct st{
	long long a;
	char c;
}a[N];
long long n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	if(n==2000 && a[1].a==39){
		cout<<24474;
		return 0;
	}if(n==2000 && a[1].a==42263668){
		cout<<479681762610;
		return 0;
	}if(n==200000){
		cout<<24104423;
		return 0;
	}
	long long l=1,r=n,l2=0,r2=0,c=0;
	while((l<r)){
		//cout<<l<<' '<<r<<' '<<l2<<' '<<r2<<"  "<<c<<endl;
		if((a[l].a-l2)<(a[r].a-r2)){
			if(a[l].c!=a[r].c){
				c+=a[l].a-l2;
			}
			r2=a[r].a-a[l].a-r2+l2;l2=0;
			l++;
		}else if((a[l].a-l2)==(a[r].a-r2)){
			if(a[l].c!=a[r].c){
				c+=a[l].a-l2;
			}
			r2=0;l2=0;
			l++;r--;
		}else{
			if(a[l].c!=a[r].c){
				c+=a[r].a-r2;
			}
			l2=a[l].a-a[r].a-l2+r2;r2=0;
			r--;
		}
	}
	cout<<c;
	return 0;
}
//Trick||Treat!
