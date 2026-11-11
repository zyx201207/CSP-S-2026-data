#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

long long int n,m;
long long int a[500010];

long long int ans[500010],cnt=0,t=0;

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}

	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++){
        ans[i]=1;
	}

	for(int j=1;j<=n;j++){
        cnt=0;
        for(int i=j+1;i<=n;i++){
            if(a[i]==a[i-1]){
                ans[j]++;
                continue;
            }

            cnt+=(i-j)*(a[i]-a[i-1]);
            if(cnt>m){
                continue;
            }

            //cout<<(i-j)*(a[i]-a[i-1])<<endl;
            if(cnt<=m){
                ans[j]=i-j+1;

                //cout<<ans[j]<<' '<<cnt<<endl;
            }
        }
        //cout<<endl;
	}

    for(int i=1;i<=n;i++){
        t=max(t,ans[i]);
    }

    cout<<t;

	return 0;
}
