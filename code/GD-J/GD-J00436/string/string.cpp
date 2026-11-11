#include <iostream>
using namespace std;
void js(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
const int N=2e5+10;
struct node{
	int s;
	char c;
}a[N];
long long sum,x;
char xc,xxc;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	js();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].c;
	bool ff=0;
	for(int i=2;i<=n;i++){
		if(a[i].c!=a[i-1].c) ff=1;
	}
	if(!ff){
		cout<<0;
		return 0;
	}
	int i=1,j=n,f=0;
	while(i<j){
		int mx,mn;
		if(x){
			int z=(f==-1?i:j);
			mx=mn=0;
			if(x<a[z].s){
				mx=a[z].s;
				xxc=a[z].c;
				mn=x;
				f=-1;
			}
			else if(x>a[z].s){
				f=1;
				mx=x;
				mn=a[z].s;
				xxc=xc;
			}
			else{
				mx=mn=x;
				xxc=xc;
				f=0;
			}
			if(xc!=a[z].c){
				sum+=mn;
			}
			x=mx-mn;
			xc=xxc;
			if(x){
				if(f==-1) i++;
				else j--;
			}
			else i++,j--;
		}
		if(!x){
			mx=mn=0;
			if(a[i].s<a[j].s){
				mx=a[j].s;
				mn=a[i].s;
				xc=a[j].c;
				f=-1;
			}
			else if(a[i].s>a[j].s){
				f=1;
				mx=a[i].s;
				mn=a[j].s;
				xc=a[i].c;
			}
			else{
				mx=mn=a[j].s;
				f=0;
				xc=a[i].c;
			}
			if(a[i].c!=a[j].c){
				cout<<i<<' '<<j<<'\n'<<'\n';
				sum+=mn;
			}
			x=mx-mn;
			if(x){
				if(f==-1) i++;
				else j--;
			}
			else i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
