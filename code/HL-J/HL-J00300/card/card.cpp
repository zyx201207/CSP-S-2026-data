#include <iostream>
using namespace std;
int a[1000005];
int b[1000005];
int s[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) {
        int x=i;
        for(int j=i;j<=n;j++,x++) {
            for(int k=1;k<=j-1;k++) {
                if(b[k]==a[j]){
                    x=k+1;
                    for(int l=k+1;l<=j-1;l++) b[l]=0;
                }
            }
            b[x]=a[j];
        }
        for(int j=1;j<=m;j++) {
//    	cout << b[j] << " ";
        	s[b[j]]++;
		}
//		cout << "\n";
    }
    for(int i=1;i<=m;i++) cout << s[i] << " ";
    return 0;
}
/*
4 3
1 2 1 3
*/
