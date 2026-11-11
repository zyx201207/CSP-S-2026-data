#include<bits/stdc++.h>
using namespace std;
#define int long long
char ch[2000010];
int a[2000010];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int l=1,r=n;
    int xb1=0,xb2=0;
    while(l<=r){
        if(ch[l]!=ch[r]){
            if(a[l]-xb1<a[r]-xb2){
                ans=ans+a[l]-xb1;
                xb2=xb2+(a[l]-xb1);
                l++;
                xb1=0;
            }else if(a[l]-xb1==a[r]-xb2){
                ans=ans+a[l]-xb1;
                xb1=0;
                xb2=0;
                l++;
                r--;
            }else{
                ans=ans+a[r]-xb2;
                xb1=xb1+(a[r]-xb2);
                r--;
                xb2=0;
            }
        }else{
            if(a[l]-xb1<a[r]-xb2){
                xb2=xb2+(a[l]-xb1);
                l++;
                xb1=0;
            }else if(a[l]-xb1==a[r]-xb2){
                xb1=0;
                xb2=0;
                l++;
                r--;
            }else{
                xb1=xb1+(a[r]-xb2);
                r--;
                xb2=0;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
