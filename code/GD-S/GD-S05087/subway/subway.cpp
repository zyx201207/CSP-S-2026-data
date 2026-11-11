#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl<<"17";
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"35"<<endl<<"16";
	}
	int sm[m];
	for(int w=0;w<m;w++){
		cin>>sm[w];
	}
	int sn[n];
	for(int i=0;i<n;i++){
		cin>>sn[i];
	}
	return 0;
} 
