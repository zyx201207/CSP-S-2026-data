#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005],r=1;
long long cnt;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
        cin >> a[i];
	}
	sort(a+1,a+n+1);

	cnt=a[n];
	for(int i=1;i<=m-1;i++){
        int q=cnt&=a[n-i],q1=n-i;
        for(int j=i+1;j<=n-r;j++){
            if(a[n-j]==-1)continue;
            if(cnt&a[n-j]>q){
                q=cnt&a[n-j];
                q1=n-j;
            }
        }
        cnt=q;
        a[q1]=-1;
        r--;
	}
	cout << cnt;

    return 0;
}
