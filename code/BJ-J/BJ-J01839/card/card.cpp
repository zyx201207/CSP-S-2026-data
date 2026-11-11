#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector <long long> cnt(m+1);
    for(int i=0;i<n;i++){
        vector<bool> book(m+1);
        vector<long long> b;
        for(int j=i;j<n;j++){
            if(book[a[j]]==0){
                book[a[j]]=1;
                b.push_back(a[j]);
            }
            else{
                int k=b.size()-1;
                while(b[k]!=a[j]){
                    book[b[k]]=0;
                    b.pop_back();
                    k--;
                }
            }
        }
        for(int j=0;j<b.size();j++){
            cnt[b[j]]++;
            //cout << b[j] << " ";
        }
        //cout << "\n";/
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    cout << "\n";
    return 0;
}
