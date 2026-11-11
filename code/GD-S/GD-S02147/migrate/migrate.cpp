#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int cf[N],x[N];
bool flg=0;
bool pd(int u,int v,int d){
	for(int i=u+1;i<=v;i++){
		if(cf[i]>d){
			return false;
		}
	}
	if(u>v){
		swap(u,v);
	}
	if(abs(v-u)==2 && abs(cf[v+1]+cf[v+2])<d){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		bool flg1=1;
		for(int i=2;i<=n;i++){
			cf[i]=abs(x[i]-x[i-1]);
			if(cf[i]!=cf[i-1]&&i>2){
				flg1=0;
			}
		}
		if(flg1){
			cout<<(n+1)/2-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				flg=0;
				if(pd(i,j,d)){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 