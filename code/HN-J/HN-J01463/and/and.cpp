#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[20005],b[20005][21]={0},c[31];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int pos_max=0;
	int cnt=0;
	for(int i=n-1;i>=n-m;i--){
		int tmp=a[i];
		int pos=0;
		while(tmp>0){
			b[i][pos]=tmp%2;
			tmp/=2;
			pos++;
			pos_max=max(pos,pos_max);
		}
	}
	for(int i=0;i<=pos_max;i++) c[i]=1;
	for(int i=n-1;i>n-m;i--){
		for(int j=0;j<=pos_max;j++){
			if(!(b[i][j]&b[i-1][j])){
				c[j]=0;
				
			}
		}
	}
	//cout<<c[0]<<c[1]<<c[2]<<c[3]<<c[4]<<endl<<pos_max<<endl;
	int ans=0;
	for(int i=pos_max;i>=0;i--){
		int tmp=1;
		if(c[i]==0) continue;
		for(int j=0;j<i;j++){
			tmp*=2;
		}
		ans+=tmp;
	}
	cout<<ans;
	return 0;
}
