#include <bits/stdc++.h>
using namespace std;
struct qwe{
	int zhi;
	int zg=1;
	int xx=0;
	
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for (int tt=1;tt<=t;tt++){
		int n,d;
		cin>>n>>d;
		qwe a[n+1];
		for (int i=1;i<=n;i++){
			cin>>a[i].zhi;
		}
		a[1].zg=0;
//		a[1].xx=0;
		int s=0;
		int u=0;
		while (u<n){
			u++;
		 	for (int j=u;j<=n;j++){
		    	if (a[j].zg==0){
					a[j].zg=1;
					for (int i=j+1;i<=n;i++){
						if (a[i].zhi-a[j].zhi<=d){
							a[i].xx++;
						}
						else {
							break;
						}
					}
				}
				else{
					break;
				}
		    }
		    for (int i=1;i<=n;i++){
//				cout<<a[i].xx<<" ";
				if (a[i].xx>0){
					a[i].zg=0;
				}
				
				if (a[i].xx==2){
					s++;
				}
				a[i].xx=0;
			}
//		    cout<<endl;
		    
		}
		cout<<s<<endl;
	}
	return 0;
}
