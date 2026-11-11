#include<bits/stdc++.h>
using namespace std;
int a[200010],num,ans;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
        cin>>a[i];
	}
	sort(a+1,a+1+m);
	int k=1,ma=a[m];
	for(int i=1;i<=n-1;i++){
        for(int j=m-k;j>=1;j--){
            if(ans<=a[j]&ma){
                ans=a[j]&ma;
                num=j;
            }
        }
        k=m-num+1;
        ma=ans,ans=0;
	}
	cout<<ma;
    return 0;
}

