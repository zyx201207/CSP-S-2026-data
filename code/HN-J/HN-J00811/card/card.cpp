#include<bits/stdc++.h>
using namespace std;
int n,m,ans,b,bbb[500005],idtk;
string z,k;
bool zm[200005];

void cc(int q,int w){
	for(int i=q;i<=w;i++){
		k[i]=0;
	}
}

void pd(int s,char q){
	for(int i=0;i<=s;i++){
		if(k[i]==q){
			cc(i+1,s-i);
			return;
		}
	}
}

void zp(int a){
	int lk=0;
	for(int i=a;i<n;i++){
		k[lk]=z[i];
		lk++;
		pd(lk,z[i]);
	}
	for(int j=1;j<=m;j++){
		for(int i=0;i<lk;i++){
			if(k[i]==j){
				bbb[j]++;
				break;
			}
		}
	}
//	for(int i=0;i<lk;i++)
//		cout<<k[i]+0<<' ';
//	cout<<endl;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b;
		z[i]=b;
	}
	for(int i=0;i<n;i++)
		zp(i);
	for(int i=1;i<=m;i++)
		cout<<bbb[i]<<' ';
	return 0;
}
