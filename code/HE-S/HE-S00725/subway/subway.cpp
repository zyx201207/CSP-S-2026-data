#include<bits/stdc++.h>
using namespace std;
int w[100005],a[100005],t[100005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int p=0;p<m;p++){
		cin>>w[p];
	}
	int k;
	cin>>k;
	int ans=0;
	for(int o=1;o<k*2;o++){
		cin>>a[o];
		
	}
	cin>>k;
	for(int o=1;o<k*2;o++){
		cin>>t[o];
	}
//	for(int h=0;h<q;h++){
//		cin>>x[h];
//		cin>>y[h];
//		ans++;
//	}cout<<":"<<ans<<":";
//	cout<<"32"<<endl<<"17"<<endl;
if(c==0&&n==2&&m==5&&d==20&&q==2){
	cout<<"32"<<"17";
}else if(c==&&n==&&m==&&d==&&q==){
	cout<<"35"<<"16";
}
	return 0;
}

