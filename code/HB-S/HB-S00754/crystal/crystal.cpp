#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
        for(int i=n;i>=2;i--){
            long long ser=0,j=i-1;
            while(ser<=m && j>=1){
                if(ser+a[i]-a[j]<=m){
                    ser=ser+a[i]-a[j];
                    j--;
                }
                else{
                    break;
                }
            }
            if(j==0){
                cout<<i;
                return 0;
            }
            else{
                ans=max(ans,i-j);
            }
        }
        cout<<ans;
    }
	else{
        long long ser;
        long long gc=a[2]-a[1];
        m/=gc;
        ser=sqrt(m*2);
        if(ser*(ser+1)>2*m){
            ser--;
        }
        cout<<min(n,ser+1);
	}
	return 0;
}
