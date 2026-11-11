#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int cnt = 0;
    int a[110000];
    int c[110000];
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    for(int i = 1;i<=n;i++){
        for(int j = 1+cnt;j<=n;j++){
            if(j>1){
				for(int k = 1;k<=j-1;k++){
					if(c[k] == a[j]){
						
					}
				}
			}
			else{	
				c[j] = a[j];
			}
        }
        cout << " ";
        cnt++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
