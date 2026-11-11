//GZ-J00697 李昂泽 贵州师范大学附属中学
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]){
                int ma=a[i];
                int t=1;
            }
        }
        if(t){
            cout<<ma;
            return 0;
        }
	}
	for(int i=1;i<=n;i++){
	    b[i]=a[i]%2;
	    a[i]/=2;
	}
	for(int i=1;i<=n;i++){
        int s=b[i]/10;
        if(b[i]==0){
            break;
        }
        else{
            c[i]=a[i];
        }
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x=c[i]&c[j];
        }
    }
    cout<<x;
    return 0;
}
