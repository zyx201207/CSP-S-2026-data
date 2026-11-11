#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num=1;
    cin>>n>>m;
    int cards[n+5];
    int conn[m+5];
    for(int i=0;i<m+5;i++){
        conn[i]=0;
    }
    int aa[n+5];
	for(int i=1;i<=n;i++){
        cin>>cards[i];
	}
    for(int i=0;i<n;i++){
        num=1;
        int att=i+1;
        for(int j=att;j<=n;j++){
            for(int k=1;k<=num;k++){
                if(cards[j]==aa[k]){
                    num=k;
                    break;
                }
            }
            aa[num]=cards[j];
            num++;
        }
        for(int h=1;h<num;h++) {
            conn[aa[h]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<conn[i]<<' ';
	return 0;
}
