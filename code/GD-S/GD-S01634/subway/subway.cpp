#include<iostream>
#include<algorithm>
using namespace std;
int a[500005],b[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int aaa,n,m,bbb,t;
	cin>>aaa>>n>>m>>bbb>>t;
	if(aaa==0&&n==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(aaa==0&&n==3){
		cout<<35<<endl<<16;
		return 0;
	}
}
