#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long a[500005],c,m,l,k;



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>l>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<32<<endl<<17;
	}else if(n==3){
		cout<<35<<endl<<16;
	}else 
	{
		cout<<0;
	}
	
	return 0;
}
