#include<bits/stdc++.h>
using namespace std;
int sum,c,n,m,d,q,w[10000005],k[1000],a[10000005],t[10000005],x[10000005],y[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	int n=1;
	while(n>=2){
		cin << k[n];
	    for(int i=1;i<=n;i++){
		    cin >> a[i] >> t[i];
	    }
	    n++;
	}
	for(int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	} 
	while(2--){
		for(int i=1;i<=n;i++){
		    if(w[i]<w[i+1]){
			   sum+=w[i];
		    }
		    if(t[i]<t[i+1]){
			   sum+=t[i];
		    }
	    }
		cout << sum << endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
