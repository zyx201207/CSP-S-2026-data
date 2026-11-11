#include<bits/stdc++.h>
using namespace std;

int const maxn=1e6;
int a[maxn];
int b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,A=0,B=0;
	long long m;
	long cnt;
	cin>>n>>m;
	for(int i=1,d=0,od=0;i<=n;i++){
		cin>>a[i];
		d=a[i]-a[i-1];
		cnt+=a[i];
        if(a[i]==i) A++;
        if(i!=1 && d==od) B++;
        od=d;
	}
	if(A==n){
        int nm=m,ans=0;
        for(int i=1;i<=m;i++){
            for(int k=1;k<=2;k++){
                if(nm>=i){
                ans++;
                nm-=i;
                }
                else break;
            }
        }
        cout<<ans+1;
	}
	else if(B==n-1){
        sort(a+1,a+1+n);
        int ans=0,f=(a[n/2]+a[n/2+1])/2,nm=m;
        for(int i=1;i<=n/2;i++)
            a[i]=f-a[i];
        for(int i=n/2+1;i<=n;i++)
            a[i]=a[i]-f;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            if(nm>=a[i]){
                ans++;
                nm-=a[i];
            }
        }
        cout<<ans;
	}
	else{
	    int ans=0,f=(a[n/2]+a[n/2+1])/2,nm=m,d=0;
        sort(a+1,a+n+1);
        for(int f=1;f<=a[n];f++){
            ans=0;
            for(int i=1;i<=n/2;i++)
                b[i]=abs(f-a[i]);
            for(int i=n/2+1;i<=n;i++)
                b[i]=abs(a[i]-f);
            sort(b+1,b+1+n);
            for(int i=1;i<=n;i++){
                if(nm>=b[i]){
                    ans++;
                    nm-=b[i];
                }
            }
        d=max(ans,d);
        }
    cout<<d;
	}
	return 0;
}
