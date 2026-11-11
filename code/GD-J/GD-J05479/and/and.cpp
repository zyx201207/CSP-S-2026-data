#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200009;

bool bt[N][35],de[N],res[35];
ll cnt[35],m,n,a,oup=0;

void gbt(int i,ll b){
	int j=0;
	while(b){
		bool bit=b&1;
		bt[i][j]=bit;
		if(bit) cnt[j]++;
		b>>=1;j++;
	}
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		gbt(i,a);
	}
	
	for(int i=32;i>=0;i--){
		//for(int z=0;z<32;z++) cout<<cnt[z]<<'/'; cout<<endl;
		if(cnt[i]<m) continue;
		res[i]=1;
		for(int k=i-1;k>=0;k--) cnt[k]=0;
		for(int j=0;j<n;j++){
			if(!bt[j][i]) de[j]=1;
			if(!de[j]) for(int k=i-1;k>=0;k--) cnt[k]+=(int)bt[j][k];
		}
	}
	for(int i=32;i>=0;i--){oup<<=1;oup|=res[i];}
	cout<<oup;
	return 0;
}
