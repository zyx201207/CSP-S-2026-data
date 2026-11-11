#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[10005],s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;;i++){
    	if(m==0){
    		break;
		}else{
			m--;
            a[1]++;
            sort(a+1,a+n+1);
		}
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            s++;
        }else{
        	s++;
            break;
        }
    }
    cout<<s;
    return 0;
}
