#include <iostream>

using namespace std;

int main(){
    freopen("migrate.in" ,"r" ,stdin);
    freopen("migrate.out" ,"w" ,stdout);
	int c ,t;
	long long n ,d ,b=0, ans=0;
	long long x[2000005] ,w[2000005];
	cin >> c >> t;
	for(int e=1; e<=t; e++){
        cin >> n >> d;
        b=0;
        ans=0;
        for(int i=1; i<=n; i++){
            cin >> x[i];
        }
        b=x[2]-x[1];
        for(int i=1; i<=n; i++){
            if(x[i]-x[i-1]!=b){
                b=-1;
                break;
            }
        }
        if(b>0){
            ans=n-4+1;
            if(d%b==0){
                ans=0;
            }
            cout << ans << endl;
        }
	}
	return 0;
}
