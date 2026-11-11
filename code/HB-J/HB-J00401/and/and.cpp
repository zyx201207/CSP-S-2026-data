#include<iostream>
using namespace std;

int n,m,as=0,a[200005],light[200005]={};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int s=30;s>=0;s--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(light[i]) continue;
			if((a[i]>>s)&1) cnt++;
		}
		if(cnt>=m){
			as+=(1<<s);
			for(int i=1;i<=n;i++){
				if(light[i]) continue;
				if(!((a[i]>>s)&1)) light[i]=1;
			}
		}
	}
	cout<<as;
	return 0;
}
