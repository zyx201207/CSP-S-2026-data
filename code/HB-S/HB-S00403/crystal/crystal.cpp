#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int h=0;
    a[0]=100000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    int p=0;
    int maxx=1;
    int s=a[1]-a[0];
    int y=0;
    if(n<=pow(10,9)){
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>m){
                p++;
            }
            if(a[i]-a[i-1]==s){
				y++;
			}
        }
        if(p==n-1){
            cout<<1;
            return 0;
        }
        if(n==1){
            cout<<1;
            return 0;
        }else if(n==2){
            cout<<2;
            return 0;
        }
    }
    if(y==n+1){
		long long nn=b[0];
		for(int i=1;i<=n;i++){
			b[i]=i+b[i-1];
			nn+=b[i]*s;
			if(nn>m){
				cout<<i;
				return 0;
			}
			if(nn==m){
				cout<<i+1;
				return 0;
			}
		}
	}else{
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				h=0;
				for(int k=i;k<=j;k++){
					h+=a[j]-a[k];
				}
				if(h<=m){
					if(maxx<(j-i+1)){
						maxx=j-i+1;
					}
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
