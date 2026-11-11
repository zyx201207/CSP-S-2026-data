#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans;
int c[21]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bool g=1;
		for(int j=0;j<=20;j++){
			if(a[i]==c[j]){
				g=0;
				break;
			}
		}
		if(g)f=0;
	}
    sort(a+1,a+n+1);
    if(f){
		cout<<a[n-m+1];
    }else if(n<=20){
		int ans=-1;
		for(int i=n;i>=n-m+1;i--){
			if(ans==-1)ans=a[i];
			else ans=(ans&a[i]);
		}
		cout<<ans;
    }else if(m==1){
		cout<<a[n];
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=(a[i]&a[j]);
				mx=max(mx,t);
			}
		}
		cout<<mx;
	}else if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++){
			t=(a[i]&t);
		}//10 11 100 1
		cout<<t;
	}else if(a[n]<=4){
		int a0=0,a1=0,a2=0,a3=0,a4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)a0++;
			if(a[i]==1)a1++;
			if(a[i]==2)a2++;
			if(a[i]==3)a3++;
			if(a[i]==4)a4++;
		}
		if(m<=a4)cout<<4;
		else{
			if(m<=a3)cout<<3;
			else if(m<=a2)cout<<2;
			else if(m<=a1)cout<<1;
			else if(m<=a1+a2+a3)cout<<1;
			else cout<<0;
		}
	}
    return 0;
}
