#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			a[i]=b[i];
		}
        for(long long j=i;j<=n;j++){
            for(long long k=j+1;k<=n;k++){
                if(a[j]==a[k]){
                    for(long long g=j;g<k;g++){
                        a[g]=-0x3f3f3f3f3f3f3f3f;
                    }
                }
            }
        }
        for(long long j=i;j<=n;j++){
            if(a[j]==-0x3f3f3f3f3f3f3f3f){
                continue;
            }else{
                t[a[j]]++;
            }
        }
	}
    for(long long j=1;j<=m;j++){
        cout<<t[j]<<" ";
    }
	return 0;
}
