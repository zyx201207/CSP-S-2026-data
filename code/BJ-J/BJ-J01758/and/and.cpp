#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	int n ,m ,ans=0 ,q=1073741824;
	int a[200005];
	cin >> n >> m;
	for(int i=1; i<=n; i++){
        cin >> a[i];
	}
	sort(a+1 ,a+n+1);
	if(m==1 || n==1){
        cout << a[n] << endl;
        return 0;
	}
	if(m==n){
        ans=a[1]&a[2];
        if(n>=3){
            for(int i=3; i<=m; i++){
                ans=ans&a[i];
            }
        }
        cout << ans << endl;
        return 0;
	}
	if(m==2){
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                q=a[i]&a[j];
                if(q>ans){
                    ans=q;
                }
            }
        }
        cout << ans << endl;
        return 0;
	}
	if(m==n-1){
            ans=0;
        for(int g=1; g<=n; g++){
            for(int i=1; i<=n; i++){
                if(i==g){
                    continue;
                }
                q=q&a[i];
            }
            if(q>ans){
                ans=q;
            }
        }
        cout << ans << endl;
        return 0;
	}
	if(a[1]<4 && a[2]<4 && a[3]<4 && a[4]<4){
        cout << 0 << endl;
        return 0;
	}
        cout << a[1] << endl;
	return 0;
}
