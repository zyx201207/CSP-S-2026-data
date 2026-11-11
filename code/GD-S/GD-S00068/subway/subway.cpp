#include<bits/stdc++.h>
using namespace std;
long long a[500005];
struct str{
	int sta;
	int tim; 
};
str lin[550][500005];
int c,n,m,d,q,k,lf,le,turi,turj;
int find(int f){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(lin[i][j].sta==f) return i;
		}
	}
	return 0;
}
int find2(int f){
	for(int j=1;j<=k;j++){
		if(lin[le][j].sta==f) return j;
	}

	return 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>lin[i][j].sta>>lin[i][j].tim;
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		int f,e;
		cin>>f>>e;
		sum=sum+a[f]+a[e];
	    lf=find(f),le=find(e);
	    if(lf=le){
	        for(int i1=f;i1<=e;i1++){
	    	    sum=sum+a[i1];
	        }
	        cout<<sum<<"\n";
	    }else{
	    	for(int i1=f;i1<=k;i1++){
	    		if(find2(lin[lf][i1].sta)!=0){
	    			turj=find2(lin[lf][i1].sta),turi=i1;
				}
	        }
	        for(int j1=f;j1<=turi;j1++) sum=sum+lin[lf][j1].tim;
	        for(int j1=turj;j1<=e;j1++) sum=sum+lin[le][j1].tim;
	        cout<<sum<<"\n";
		}
	}
	return 0;
}
