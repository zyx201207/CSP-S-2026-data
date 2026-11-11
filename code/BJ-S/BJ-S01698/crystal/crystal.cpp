#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("crystal.in" ,"r" ,stdin);
    freopen("crystal.out" ,"w" ,stdout);
	long long n ,m ,sum=0 ,ans=0 ,p=0;
	long long a[500005] ,c[500005];
	cin >> n >> m;
	for(int i=1; i<=n; i++){
        cin >> a[i];
	}
	sort(a+1 ,a+n+1);
	for(int i=n; i>=1; i--){
        sum=0;
        p=0;
        for(int j=i; j>=1; j--){
            c[j]=a[i]-a[j];
            sum+=c[j];
            if(sum>m){
                break;
            }
            p++;
        }
        if(p>ans){
            ans=p;
        }
        if(ans>i){
            break;
        }
	}
	cout << ans << endl;
	return 0;
}
