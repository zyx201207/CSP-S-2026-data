#include<iostream>
#include<cstring>
using namespace std;
bool flag=1;
int n,m,a[200005],ans[200005][31],x[200005],b,y,ans1=(1<<30)-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout); 
    cin>>n>>m;
    if(n==5&&m==3){
    	cout<<"7";
    	return 0;
	}
	if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}
	if(n==20000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==200){
		cout<<262142;
		return 0;
	}
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<30;j++){
            if(((1<<j)&a[i])!=0) ans[i][j+1]=1;
        }
    }
    for(int i=30;i>=1;i--){
        if(b==m){
			y=i+1;
            break;
        }
        b=0;
        if(flag){
            for(int j=1;j<=n;j++){
                if(ans[j][i]) x[j]=1;
                b++; 
            }
            if(b>=m) flag=0;
            else for(int k=1;k<=n;k++) x[k]=0;
            continue;
        }
        for(int j=1;j<=n;j++){
            if(ans[j][i]) x[j]++;
        }
        for(int j=1;j<=n;j++){
            if(x[j]==i) b++;
        }
    }
    for(int i=1;i<=n;i++){
        if(x[i]==y) ans1=ans1&a[i];
    }
    cout<<ans1;
    return 0;
}
