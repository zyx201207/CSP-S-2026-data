#include<bits/stdc++.h>;
using namespace std;
long long w[100001];
long long a[10001];
long long t[10001];
long long x[10001];
long long y[10001];
long long check[10001]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    long long c=0,n=0,m=0,d=0,q=0,k=0,ant=0,innn=0,timee=0,e=0,f=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}for(int i=1;i<=q;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>innn>>timee;
			if(check[innn]!=0){
				if(t[innn]>=timee){
					t[innn]=timee;
			}
			}else{
				a[innn]=innn;
			t[innn]=timee;
			check[innn]=1;
			}
		}	
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		e=x[i];
		f=y[i];
		ant=w[e]+w[f];
		for(int j=x[i];j<=y[i];j++){
		ant=ant+t[j];
			if(j!=f){
				ant=ant+t[j];
			}
		}
		cout<<ant-1;
	}
	
	return 0;
} 
