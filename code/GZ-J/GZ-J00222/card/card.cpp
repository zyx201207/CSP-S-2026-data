//liYangJunYi GZ-J00222
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,n_list[1001],m,m_list[1001]={0},k1[1001],k=0;
    for(int i=0;i<n;i++) cin>>n_list[i];
    for(int i=0;i<n;i++){
        k=0;
        int k1[1001]={0};
        for(int j=i;j<n;j++){
            for(int l=0;l<k;l++){
                if(n_list[j] == k1[l]){
                    int k1[1001]={0};
                    k=0;
            }}
            k1[k]=n_list[j];
            k++;
        }
        for(int j=0;j<k;j++) m_list[k1[j]]++;
    }
    for(int i=0;i<m;i++) cout<<m_list[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
