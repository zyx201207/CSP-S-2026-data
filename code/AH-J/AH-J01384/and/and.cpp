#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[10000005];
int b2[10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	int maxx2=0;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t=a[j];
            int cnt=0;
            while(t){
                b[++cnt]=t%2;
                t/=2;
            }
            int cnt2=0;
            int t2=a[i];
            while(t2){
                b2[++cnt2]=t2%2;
                t2/=2;
            }
            int cnt3=0;
            int maxx=max(cnt,cnt2);
            for(int i=maxx;i>=1;i--){
                if(b[i]==b2[i]){
                    cnt3++;
                }
            }
            if(cnt3>maxx2){
                maxx2=cnt3;
            }
        }
	}
	cout<<maxx2;
	return 0;
}
