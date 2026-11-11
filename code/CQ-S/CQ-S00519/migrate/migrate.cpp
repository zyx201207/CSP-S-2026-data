#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;

int lyfsrkl,t;
int n,m;
long long a[N],x[N];
long long cnt_fornt[N];
int ccc;

void z(int l,int r,int k){
    if (k==1){
        if (x[r]-x[l]<=m) {
            ccc++;
        }
        return;
    }
    for (int i=l+1;i<=r;i++){
        if (x[i]-x[l]<=m) {
            z(i,r+1,k-1);
        }
        else break;
    }
    return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

    cin >> lyfsrkl >> t;
    
    while (t--){
        cin >> n >> m;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            x[i]=a[i];
        }
        cnt_fornt[0]=0;
        for (int i=2;i<=n;i++){
            cnt_fornt[i]=a[i]-a[i-1];
            cnt_fornt[i]+=cnt_fornt[i-1];
        }
        for (int i=n;i>1;i--){
            a[i]-=a[i-1];
        }
        
/*
		for (int i=1;i<=n;i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
*/
        int ans=0;
        for (int i=1;i<=n-3;i++){
            int X;
            for (int j=i+3;j<=n;j++){
                if (x[j]-x[i]<=m) continue;
                int num=0,cnt=0;
                X=0;
                for (int k=i+1;k<=j;k++){
                    num+=a[k];
                    if (num>2*m) {X=-1;break;}
                    if (num>m) cnt++,num=a[k];
                    
                }
                if (num>2*m) {X=-1;}
                if (X==-1) break;
                if (num>m) cnt+=2;
                if (num>0) cnt++;
                ccc=0;
                z(i,j-cnt+1,cnt);
                if (ccc==2) ans++;
            }
            if (X==-1) break;
        }
        cout << ans << '\n';
    }
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
