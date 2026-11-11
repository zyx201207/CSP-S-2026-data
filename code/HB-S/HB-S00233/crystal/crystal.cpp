#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],ans=1,ans2=1,ans1=1;
int b[1000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
    }
    int cnt;
    for(int i=2;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
             b[1]=a[1]+(m-k+1);
             cnt=a[1]+m-b[1];
             if(cnt<=1)
             {
                 b[i]=a[i]+cnt;
                 if(b[i]==b[k]){
					 ans1++;
					 }	 
                 }
             else{
                 for(int j=2;j<=n;j++)
                 {
					 b[j]=a[k]+cnt;
			         int cnt1=cnt-j+1;
					 for(int l=1;l<=cnt1;l++){
                     b[j+1]=a[j]+l;
                 }
         				if(b[j-1]==b[j]){
					       ans2++;			         
					       ans=max(ans1,ans2);
					}
			            else{
							   ans2=1;
					}
				}
             }
        }
    }
    cout << ans;
    return 0;
}
