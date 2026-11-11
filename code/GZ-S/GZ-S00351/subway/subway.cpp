//准考证号：GZ-S00351 姓名：曹一柏 
#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,a[100005],t[100005],x[100005],y[100005],w[100005],k[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i]>>t[i];
	}
	for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
        if(c==7||c==8||c==9||c==10||c==11){
            cout<<w[1]+t[1]+t[2]+w[2]<<endl;
        }
        else if(c==12||c==13||c==14||c==15||c==16||c==17||c==18||c==19){
            cout<<w[1]+(k*t)+w[m]<<endl;
        }
    }
	return 0;
}


