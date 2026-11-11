#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<char>a;
    vector<char>b;
    vector<int>c;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }

    for(int r=0;r<n;r++){
            int s=0;
        while(s+1){
            int i=0;
            int l=0;
            for(int j=0;j<i;j++){
                if(a[i]==b[j]){
                    l=j;
                    break;
                }
            }
            if(l){
                for(int j=l+1;<getline(b);j++){
                    b[j]=0;
                    s--;
                }
            }
            b.push_back(a[i]);
            s++;
            i++;
        }
        for(int i=0;i<s;i++){
            c[b[i]]++;
        }
}
  for(int i=0;i<m;i++){
    cout<<c[i];
  }
    fclose(stdin);
    fclose(stdout);
return 0;}
