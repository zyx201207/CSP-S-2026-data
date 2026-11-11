#include <bits/stdc++.h>
using namespace std;

int a[50005],b[30005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
        cin >> a[i];
	}
	for(int i=1;i<=n;i++){
        int c[50005]={};
        for(int q=1;q<=n;q++){
            for(int j=q+1;j<=n;j++){
                if(a[q]==a[j]){
                    int s=j-1;
                    while(s>=q){
                        c[a[s]]++;
                        s--;
                    }
                    break;
                }
            }
        }
        for(int q=1;q<=m;q++){
            if(c[q]==0){
                b[q]++;
            }
        }
	}
	for(int i=1;i<=m;i++)
        cout << b[i] << " ";
	return 0;
}

