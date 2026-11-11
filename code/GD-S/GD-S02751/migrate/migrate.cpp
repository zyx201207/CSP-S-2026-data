#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c ,t;
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n ,d;
		cin >> n >> d;
		int a[n+5];
		long long shu=0;
		for(int j=1;j<=n;j++){
			cin >> a[j];
		}
		if(a[1]<a[2]){
			for(int q=1;q<=n;q++){
			    for(int w=q+1;w<=n;w++){
				    if(a[w]-a[w-1]<=d){
					    int e=a[w]-a[i];
					    if(e%n==1){
					    	shu++;
						}
				    }
			    }
		    }
		}else{
			for(int q=n;q>=1;q--){
			    for(int w=n;w>=q+1;w--){
				    if(a[w]-a[w-1]<=d){
					    int e=a[w]-a[i];
					    if(e%n==1){
					    	shu++;
						}
				    }
			    }
		    }
		}

		cout << shu <<endl;
	}
	return 0;
}
