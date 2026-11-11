#include <bits/stdc++.h>
using namespace std;
int const N=2*1e5+5;
unsigned long long n,d,cnt=0,b[N],e=0,f;
char a[N],c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c;
		cnt+=b[i];
		if(i==1){
			f=1;
		}else f+=b[i-1];
		for(int j=f;j<=cnt;j++){
			a[j]=c;
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<a[i]<<" ";
//	}
	if(cnt%2==1){
		d=1;
	}else d=2;
//	cout<<"cnt="<<cnt<<endl;
//	cout<<"d="<<d<<endl;
//	cout<<endl;
	for(int i=1;i>=0;i++){
		if(a[i]!=a[cnt-i+1]){
			e++;
		}
//		cout<<"a["<<i<<"]="<<a[i]<<endl;
//		cout<<"a["<<cnt-i+1<<"]="<<a[cnt-i+1]<<endl;
		if(d==1 && i-1==cnt-i){
			cout<<e;
			return 0;
		}else if(d==2 && i+1==cnt-i){
			cout<<e;
			return 0;
		}
//		cout<<"i="<<i<<endl;
//		cout<<"e="<<e<<endl;
//		cout<<endl;
	}
	return 0;
}
